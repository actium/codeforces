#include <iostream>

constexpr unsigned M = 1000000007;

unsigned raise(unsigned base, unsigned power)
{
    using integer = unsigned long long;

    integer v = 1;
    for (integer b = base; power != 0; power /= 2) {
        if (power % 2 == 1)
            v = v * b % M;

        b = b * b % M;
    }
    return v;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m)
{
    answer(raise(raise(2, m) - 1, n));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
