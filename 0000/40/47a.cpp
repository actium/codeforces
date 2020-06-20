#include <iostream>

#include <cmath>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n)
{
    const unsigned k = sqrt(2 * n);
    answer(k * (k+1) / 2 == n || (k+1) * (k+2) / 2 == n);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

