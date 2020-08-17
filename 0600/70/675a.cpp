#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(int a, int b, int c)
{
    if (c == 0)
        return answer(b == a);

    answer((b - a) % c == 0 && (b - a) / c >= 0);
}

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}

