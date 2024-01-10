#include <array>
#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned l, unsigned r)
{
    using integer = unsigned long long;

    constexpr unsigned M = 1000000007;

    const std::array<unsigned, 3> q = {
        r / 3 - (l - 1) / 3,
        (r - 1) / 3 - (l + 1) / 3 + 1,
        (r + 1) / 3 - l / 3,
    };

    std::array<integer, 3> k = { q[0], q[1], q[2] };
    for (unsigned i = 1; i < n; ++i) {
        std::array<integer, 3> c = {
            (k[0] * q[0] % M + k[1] * q[2] % M + k[2] * q[1] % M) % M,
            (k[0] * q[1] % M + k[1] * q[0] % M + k[2] * q[2] % M) % M,
            (k[0] * q[2] % M + k[2] * q[0] % M + k[1] * q[1] % M) % M,
        };
        std::swap(k, c);
    }

    answer(k[0]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, l, r;
    std::cin >> n >> l >> r;

    solve(n, l, r);

    return 0;
}
