#include <iostream>
#include <numeric>
#include <vector>

constexpr unsigned oo = ~0u >> 1;
constexpr unsigned N = 5000;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void relax(unsigned& x, unsigned v)
{
    if (v < x)
        x = v;
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned g = 0;
    for (const unsigned x : a)
        g = std::gcd(g, x);

    unsigned k = 0;
    for (const unsigned x : a)
        k += (x == g);

    if (k != 0)
        return answer(n - k);

    std::vector<unsigned> dp(1 + N, oo);
    dp[0] = 0;
    for (size_t i = 0; i < n; ++i) {
        for (unsigned x = 0; x <= N; ++x)
            relax(dp[std::gcd(a[i], x)], dp[x] + 1);
    }

    answer(n + dp[g] - 2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
