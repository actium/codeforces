#include <iostream>

void answer(unsigned long long x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    answer(m == 1 ? n - 1 : n * (m - 1ull));
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
