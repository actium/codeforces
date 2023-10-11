#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::vector<unsigned> p(1 + k, n), s(1 + k);
    for (size_t i = 0; i < n; ++i) {
        if (p[a[i]] == n)
            p[a[i]] = i;

        s[a[i]] = i;
    }

    std::vector<unsigned> dp = p, ds = s;
    for (size_t i = k; i > 0; --i) {
        dp[i-1] = std::min(dp[i-1], dp[i]);
        ds[i-1] = std::max(ds[i-1], ds[i]);
    }

    std::vector<unsigned> b(k);
    for (const unsigned x : a) {
        if (p[x] != n)
            b[x-1] = 2 * (ds[x] - dp[x] + 1);
    }

    answer(b);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
