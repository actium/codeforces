#include <iostream>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    answer(3ull * n * (n + 1) + 1);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

