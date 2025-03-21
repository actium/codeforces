#include <iostream>

using integer = unsigned long long;

constexpr unsigned M = 1'000'000'007;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned raise(integer b, integer p)
{
    unsigned v = 1;
    for (b %= M; p != 0; p /= 2) {
        if (p % 2 == 1)
            v = v * b % M;

        b = b * b % M;
    }
    return v;
}

void solve(unsigned x, integer n)
{
    integer v = 1;

    const auto check = [&](unsigned d) {
        if (d < 2 || x % d != 0)
            return;

        integer q = 1;
        while (q * d % d == 0 && q * d <= n)
            q *= d;

        for (integer k = 0; q != 1; q /= d) {
            const integer c = n / q - k;
            v = v * raise(q, c) % M;
            k += c;
        }

        while (x % d == 0)
            x /= d;
    };

    for (unsigned d = 2; d * d <= x; ++d)
        check(d);

    check(x);

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned x;
    std::cin >> x;

    integer n;
    std::cin >> n;

    solve(x, n);

    return 0;
}
