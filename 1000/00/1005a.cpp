#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(1, 0);
    for (size_t i = 0; i < n; ++i) {
        unsigned a;
        std::cin >> a;

        if (a > b.back())
            b.back() = a;
        else
            b.push_back(a);
    }

    answer(b);

    return 0;
}

