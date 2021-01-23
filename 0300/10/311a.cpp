#include <iostream>

void no_answer()
{
    std::cout << "no solution" << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (n * (n - 1) / 2 <= k)
        return no_answer();

    for (unsigned x = 0; x < n; ++x)
        std::cout << 0 << ' ' << x << '\n';
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

