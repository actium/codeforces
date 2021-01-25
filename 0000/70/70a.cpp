#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    constexpr unsigned M = 1000003;

    unsigned long long v = 1;
    while (n-- > 1)
        v = (v * 3) % M;

    answer(v);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

