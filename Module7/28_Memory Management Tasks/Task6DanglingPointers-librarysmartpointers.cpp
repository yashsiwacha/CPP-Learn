#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Book
{
public:
    std::string title;
    std::string author;

    Book(const std::string &t, const std::string &a) : title(t), author(a) {}

    void print() const
    {
        std::cout << "Book: " << title << " by " << author << std::endl;
    }
};

class Library
{
private:
    std::vector<std::unique_ptr<Book>> books;

public:
    void addBook(const std::string &title, const std::string &author)
    {
        books.push_back(std::make_unique<Book>(title, author));
    }

    Book *findBook(const std::string &title)
    {
        for (const auto &book : books)
        {
            if (book->title == title)
            {
                return book.get(); // Non-owning observer pointer
            }
        }
        return nullptr;
    }

    bool removeBook(const std::string &title)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
        {
            if ((*it)->title == title)
            {
                books.erase(it); // unique_ptr automatically deletes the Book
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Library lib;
    lib.addBook("1984", "George Orwell");
    lib.addBook("Brave New World", "Aldous Huxley");

    Book *bookPtr = lib.findBook("1984");
    if (bookPtr)
    {
        std::cout << "[before remove] ";
        bookPtr->print();
    }

    const bool removed = lib.removeBook("1984");
    std::cout << "Removed 1984: " << (removed ? "yes" : "no") << std::endl;

    // Important: after removal, old observer pointers are invalid.
    // Resetting avoids accidental use of a dangling pointer.
    bookPtr = nullptr;

    std::cout << "Trying to access removed book safely:" << std::endl;
    if (bookPtr)
    {
        bookPtr->print();
    }
    else
    {
        std::cout << "Pointer reset to nullptr. No dangling access." << std::endl;
    }

    std::cout << "\nSummary:" << std::endl;
    std::cout << "- Use std::unique_ptr for clear single ownership of Book objects." << std::endl;
    std::cout << "- Avoid keeping raw pointers after erase/remove operations." << std::endl;
    std::cout << "- If you keep an observer pointer, invalidate it (set to nullptr) when object is removed." << std::endl;

    return 0;
}
