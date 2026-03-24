#include <iostream>
#include <vector>
#include <string>
#include <map>

int main()
{
    std::vector<std::pair<int, std::string>> v{{1, "A"}, {2, "B"}};

    // auto& keeps references to existing elements (no copy), so num/str refer to each pair's fields.
    // Use const auto& for read-only access when you only need to print values.
    for (auto &[num, str] : v)
    {
        std::cout << "Number: " << num << ", String: " << str << std::endl;
    }

    std::map<int, std::string> idToName{{10, "X"}, {20, "Y"}};
    for (const auto &[id, name] : idToName)
    {
        std::cout << "Map entry -> ID: " << id << ", Name: " << name << std::endl;
    }

    return 0;
}
