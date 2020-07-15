#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(int a, int b, unsigned s)
{
    const unsigned d = std::abs(a) + std::abs(b);

    answer(d <= s && (s - d) % 2 == 0);
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    unsigned s;
    std::cin >> s;

    solve(a, b, s);

    return 0;
}

