#include <iostream>
#include <vector>

using integer = unsigned long long;

constexpr unsigned M = 1000000007;

integer raise(integer b, integer p)
{
    integer v = 1;
    while (p != 0) {
        if (p % 2 == 1)
            v = v * b % M;

        b = b * b % M;
        p /= 2;
    }
    return v;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(size_t n, size_t k, const std::vector<unsigned>& f)
{
    if (f.empty())
        return answer(0);

    const integer q = n * (n - 1ull) / 2 % M, x = raise(q, M - 2);

    integer s = k * (k - 1ull) / 2 % M * f.size() % M;
    for (const unsigned c : f) {
        s += q * c % M * k % M;
        s %= M;
    }

    answer(s * x % M * x % M);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> f(m);
    for (size_t i = 0; i < m; ++i) {
        unsigned a, b;
        std::cin >> a >> b >> f[i];
    }

    solve(n, k, f);
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
