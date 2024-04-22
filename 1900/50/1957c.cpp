#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& t)
{
    for (const std::pair<unsigned, unsigned>& e : t)
        n -= (e.first == e.second ? 1 : 2);

    std::vector<unsigned> dp(1 + n, 1);
    for (unsigned i = 2; i <= n; ++i)
        dp[i] = (dp[i-1] + 2 * (i - 1ull) * dp[i-2]) % 1000000007;

    answer(dp[n]);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::pair<unsigned, unsigned>> t(k);
    std::cin >> t;

    solve(n, t);
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
