#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Book stores one record that will be persisted to a text file.
class Book
{
private:
    string title;
    string author;
    double price;

public:
    Book() : title(""), author(""), price(0.0) {}

    Book(const string &title, const string &author, double price)
        : title(title), author(author), price(price) {}

    void print() const
    {
        cout << "Title : " << title << '\n';
        cout << "Author: " << author << '\n';
        cout << fixed << setprecision(2) << "Price : $" << price << "\n";
    }

    // Friend functions are used so file I/O helpers can access private members
    // directly without exposing getters/setters only for persistence.
    friend void saveToFile(const Book &book, ofstream &ofs);
    friend Book loadFromFile(ifstream &ifs);
};

// Writes one complete book record in 3 lines:
// line 1 -> title, line 2 -> author, line 3 -> price.
// This fixed layout makes loading predictable and simple.
void saveToFile(const Book &book, ofstream &ofs)
{
    ofs << book.title << '\n'
        << book.author << '\n'
        << book.price << '\n';
}

// Reads one complete book record from file using the same 3-line layout.
// If a record is incomplete/invalid, failbit is set so caller can stop safely.
Book loadFromFile(ifstream &ifs)
{
    string title;
    string author;
    string priceText;

    // Read title. If EOF is reached here, no more records exist.
    if (!getline(ifs, title))
    {
        return Book();
    }

    // Missing author means incomplete record.
    if (!getline(ifs, author))
    {
        ifs.setstate(ios::failbit);
        return Book();
    }

    // Missing/invalid price also means corrupt or incomplete record.
    if (!getline(ifs, priceText))
    {
        ifs.setstate(ios::failbit);
        return Book();
    }

    double price;
    return Book(title, author, price);
}

int main()
{
    // Step 1: Read number of books from user.
    int count;
    cout << "Enter number of books: ";
    cin >> count;

    if (!cin || count < 0)
    {
        cout << "Invalid number of books.\n";
        return 1;
    }

    // Remove trailing newline so next getline reads actual text.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Step 2: Collect books in memory.
    vector<Book> books;
    books.reserve(count);

    for (int index = 0; index < count; ++index)
    {
        string title;
        string author;
        double price;

        cout << "\nEnter details for Book " << index + 1 << ":\n";
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "Price: ";
        cin >> price;

        if (!cin)
        {
            cout << "Invalid price input.\n";
            return 1;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        books.emplace_back(title, author, price);
    }

    // Step 3: Save all records to file.
    const string fileName = "books.txt";
    ofstream ofs(fileName);
    if (!ofs)
    {
        cout << "Error: could not open file '" << fileName << "' for writing.\n";
        return 1;
    }

    for (const Book &book : books)
    {
        saveToFile(book, ofs);
    }
    ofs.close();

    // Step 4: Load records back from file to verify persistence.
    ifstream ifs(fileName);
    if (!ifs)
    {
        cout << "Error: could not open file '" << fileName << "' for reading.\n";
        return 1;
    }

    vector<Book> loadedBooks;
    // Keep reading until stream indicates no valid next record.
    while (true)
    {
        Book book = loadFromFile(ifs);
        if (!ifs)
        {
            break;
        }
        loadedBooks.push_back(book);
    }

    cout << "\nBooks loaded from file:\n";
    cout << "=======================\n";
    for (size_t index = 0; index < loadedBooks.size(); ++index)
    {
        cout << "Book " << index + 1 << ":\n";
        loadedBooks[index].print();
        cout << "-----------------------\n";
    }

    return 0;
}