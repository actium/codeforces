#include <iostream>

void answer(size_t v)
{
    constexpr const char* s[4] = { "1 A", "0 A", "1 B", "2 A" };
    std::cout << s[v] << '\n';
}

int main()
{
    unsigned x;
    std::cin >> x;

    answer(x % 4);

    return 0;
}

