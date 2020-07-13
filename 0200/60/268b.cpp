#include <iostream>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    answer(1ull * n * (n * n + 5) / 6);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

