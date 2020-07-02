#include <iostream>

void answer(size_t v)
{
    constexpr const char* s[3] = { "Tie", "Misha", "Vasya" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned d)
{
    const unsigned s1 = std::max(3 * a / 10, a - a / 250 * c);
    const unsigned s2 = std::max(3 * b / 10, b - b / 250 * d);

    if (s1 == s2)
        answer(0);
    else
        answer(1 + (s2 > s1));
}

int main()
{
    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(a, b, c, d);

    return 0;
}

