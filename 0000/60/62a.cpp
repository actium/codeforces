#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned d)
{
    const auto check = [](unsigned g, unsigned b) {
        return b >= g - 1 && b <= g * 2 + 2;
    };

    answer(check(a, d) || check(b, c));
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    unsigned c, d;
    std::cin >> c >> d;

    solve(a, b, c, d);

    return 0;
}

