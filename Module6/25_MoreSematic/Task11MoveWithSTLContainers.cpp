#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

class MyString
{
private:
    char *data;

public:
    MyString(const char *str)
    {
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
        std::cout << "Constructed '" << data << "'"
                  << " [buffer@" << static_cast<const void *>(data) << "]" << std::endl;
    }

    MyString(const MyString &other)
    {
        if (other.data)
        {
            data = new char[std::strlen(other.data) + 1];
            std::strcpy(data, other.data);
        }
        else
        {
            data = nullptr;
        }
        std::cout << "Copied '" << (data ? data : "null") << "'"
                  << " [buffer@" << static_cast<const void *>(data) << "]" << std::endl;
    }

    MyString(MyString &&other) noexcept : data(other.data)
    {
        other.data = nullptr;
        std::cout << "Moved! (resource at " << static_cast<const void *>(data) << ")" << std::endl;
    }

    ~MyString()
    {
        std::cout << "Destructed '" << (data ? data : "null") << "'"
                  << " [buffer@" << static_cast<const void *>(data) << "]" << std::endl;
        delete[] data;
    }
};

int main()
{
    std::vector<MyString> vec;
    vec.reserve(3); // Keep output focused on insertion behavior (avoid reallocation noise).

    MyString a("first");
    MyString b("second");

    std::cout << "\n-- push_back(a) (copy): --" << std::endl;
    vec.push_back(a);

    std::cout << "\n-- push_back(std::move(b)) (move): --" << std::endl;
    vec.push_back(std::move(b));

    std::cout << "\n-- emplace_back(\"temp\") (in-place construct): --" << std::endl;
    vec.emplace_back("temp");

    std::cout << "\n-- End of main (destructors fire) --" << std::endl;
    return 0;
}
