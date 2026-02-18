#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned dp[2] = { 0, 1 };
    for (size_t i = 1; i < n; ++i) {
        const unsigned ndp[2] = {
            a[i] == a[i-1] || a[i] == 7 - a[i-1] ? dp[1] : std::min(dp[0], dp[1]),
            std::min(dp[0], dp[1]) + 1
        };
        dp[0] = ndp[0];
        dp[1] = ndp[1];
    }

    answer(std::min(dp[0], dp[1]));
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
