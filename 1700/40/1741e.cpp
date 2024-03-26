#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& b)
{
    const size_t n = b.size();

    std::vector<bool> dp(n + 1);
    dp[0] = true;
    for (size_t i = 0; i < n; ++i) {
        if (i + b[i] < n && dp[i])
            dp[i+b[i]+1] = true;

        if (b[i] <= i && dp[i-b[i]])
            dp[i+1] = true;
    }

    answer(dp[n]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(b);
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
