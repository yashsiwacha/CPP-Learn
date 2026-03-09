#include <iostream>
#include <string>
#include <tuple>

template <typename... Args>
class MyTuple
{
    std::tuple<Args...> data;

public:
    MyTuple(Args... args) : data(args...) {}

    void print() const
    {
        printHelper<0>();
        std::cout << std::endl;
    }

private:
    template <std::size_t Index>
    void printHelper() const
    {
        if constexpr (Index < sizeof...(Args))
        {
            std::cout << std::get<Index>(data) << " ";
            printHelper<Index + 1>();
        }
    }
};

int main()
{
    MyTuple<int, double, std::string> t(1, 2.5, "hello");
    t.print();
    return 0;
}
