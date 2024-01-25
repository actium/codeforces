#include <iostream>
#include <vector>

constexpr unsigned M = 1000000007;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(size_t n, const std::vector<unsigned>& s)
{
    using integer = unsigned long long;

    unsigned o = 0;
    for (const unsigned x : s)
        o |= x;

    integer v = 1;
    for (integer b = 2, p = n - 1; p != 0; p /= 2) {
        if (p % 2 == 1)
            v = v * b % M;

        b = b * b % M;
    }

    answer(o * v % M);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> s(m);
    for (size_t i = 0; i < m; ++i) {
        unsigned l, r;
        std::cin >> l >> r >> s[i];
    }

    solve(n, s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
