#include <iostream>

void answer(const char* v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned m = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned a;
        std::cin >> a;

        m |= a;
    }

    constexpr const char* s[2] = { "EASY", "HARD" };
    answer(s[m != 0]);

    return 0;
}

