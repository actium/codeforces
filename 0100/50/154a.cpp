#include <iostream>
#include <string>
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

size_t index(char c)
{
    return c - 'a';
}

void solve(const std::string& s, const std::vector<std::string>& r)
{
    const size_t n = s.length();

    std::vector<size_t> x(26, 26);
    for (const std::string& q : r) {
        x[index(q[0])] = index(q[1]);
        x[index(q[1])] = index(q[0]);
    }

    std::vector<std::vector<unsigned>> dp(1 + n, std::vector<unsigned>(26, ~0u));
    for (size_t i = 0; i < 26; ++i)
        dp[0][i] = 0;

    for (size_t i = 0; i < n; ++i) {
        const size_t c = index(s[i]);

        for (size_t j = 0; j < 26; ++j) {
            dp[i+1][j] = std::min(dp[i+1][j], dp[i][j] + 1);

            if (x[j] != c)
                dp[i+1][c] = std::min(dp[i+1][c], dp[i][j]);
        }
    }

    unsigned k = ~0u;
    for (size_t i = 0; i < 26; ++i)
        k = std::min(k, dp[n][i]);

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    size_t k;
    std::cin >> k;

    std::vector<std::string> r(k);
    std::cin >> r;

    solve(s, r);

    return 0;
}
