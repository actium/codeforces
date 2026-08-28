#include <iostream>
#include <vector>

using integer = unsigned long long;

integer score(size_t s, size_t t)
{
    const integer d = t - s + 1;
    return d * d;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = n-1; ~i != 0; --i)
        p[a[i]] = i;

    std::vector<integer> dp(1+n);
    for (size_t i = 0; i < n; ++i) {
        const auto x = p[a[i]];
        dp[i+1] = std::max(dp[i] + 1, dp[x] + score(x, i));
    }

    answer(dp[n]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
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
