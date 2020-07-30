#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned k)
{
    answer(std::min(k - 1, n - k) + 3 * n);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

