#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

// Book class models one record in the catalog.
// It stores title, author, and price, and supports stream-based input/output.
class Book
{
private:
    // Private data members to keep object state encapsulated.
    string title;
    string author;
    double price;

public:
    Book() : title(""), author(""), price(0.0) {}

    Book(const string &title, const string &author, double price)
        : title(title), author(author), price(price) {}

    friend istream &operator>>(istream &is, Book &book);
    friend ostream &operator<<(ostream &os, const Book &book);
};

// Input operator: reads a complete Book object from any input stream.
// For console input, prompts are shown; for file/stringstream input, prompts are skipped.
istream &operator>>(istream &is, Book &book)
{
    // Read title as full line to support spaces.
    if (&is == &cin)
    {
        cout << "Title: ";
    }
    getline(is, book.title);

    // Read author as full line to support spaces.
    if (&is == &cin)
    {
        cout << "Author: ";
    }
    getline(is, book.author);

    // Read numeric price.
    if (&is == &cin)
    {
        cout << "Price: ";
    }

    if (!(is >> book.price))
    {
        return is;
    }

    // Clear leftover newline after numeric input,
    // so the next getline works correctly.
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    return is;
}

// Output operator: prints one Book in a structured multi-line block.
ostream &operator<<(ostream &os, const Book &book)
{
    os << "  Title : " << book.title << '\n'
       << "  Author: " << book.author << '\n'
       << fixed << setprecision(2)
       << "  Price : $" << book.price;
    return os;
}

int main()
{
    // Step 1: Read how many books the user wants to enter.
    int count;
    cout << "Enter number of books: ";
    cin >> count;

    // Remove trailing newline after reading count.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Step 2: Prepare storage for all book records.
    vector<Book> books;
    books.reserve(count);

    // Step 3: Read each book using overloaded operator>>.
    for (int index = 0; index < count; ++index)
    {
        cout << "\nEnter details for Book " << index + 1 << ":\n";

        Book book;
        cin >> book;

        if (!cin)
        {
            cout << "Invalid input for book data.\n";
            return 1;
        }

        books.push_back(book);
    }

    // Step 4: Display all books using overloaded operator<<.
    cout << "\n========================================\n";
    cout << "              BOOK LIST                \n";
    cout << "========================================\n";

    for (size_t index = 0; index < books.size(); ++index)
    {
        cout << "Book #" << index + 1 << '\n';
        cout << "----------------------------------------\n";
        cout << books[index] << '\n';
        cout << "----------------------------------------\n\n";
    }

    cout << "Total books: " << books.size() << '\n';

    return 0;
}