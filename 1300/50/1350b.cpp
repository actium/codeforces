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

void solve(const std::vector<unsigned>& s)
{
    const size_t n = s.size();

    std::vector<unsigned> dp(1 + n, 1);
    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = i + i; j <= n; j += i) {
            if (s[i-1] < s[j-1])
                dp[j] = std::max(dp[j], dp[i] + 1);
        }
    }

    unsigned x = 0;
    for (size_t i = 1; i <= n; ++i)
        x = std::max(x, dp[i]);

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
