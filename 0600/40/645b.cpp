#include <iostream>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned k)
{
    const auto s = n * (n - 1ull) / 2;
    if (k > n / 2)
        return answer(s);

    const auto m = n - 2 * k;
    const auto d = m * (m - 1ull) / 2;
    answer(s - d);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

