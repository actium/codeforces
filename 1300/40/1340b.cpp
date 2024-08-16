#include <iostream>
#include <string>
#include <vector>

constexpr unsigned oo = ~0u >> 1;

constexpr std::string_view t[10] = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011",
};

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

unsigned distance(const std::string_view& s, const std::string_view& t)
{
    unsigned k = 0;
    for (size_t i = 0; i < 7; ++i) {
        if (s[i] == '1' && t[i] == '0')
            return oo;

        k += t[i] - s[i];
    }
    return k;
}

void solve(const std::vector<std::string>& s, size_t k)
{
    const size_t n = s.size();

    std::vector<std::vector<char>> dp(n+1, std::vector<char>(1+k));
    dp[n][0] = ' ';
    for (size_t i = n-1; ~i != 0; --i) {
        for (size_t q = 0; q < 10; ++q) {
            const unsigned d = distance(s[i], t[q]);

            for (size_t j = 0; j + d <= k; ++j) {
                if (dp[i+1][j] != '\0')
                    dp[i][j+d] = '0' + q;
            }
        }
    }

    if (dp[0][k] == '\0')
        return no_answer();

    std::string v;
    for (size_t i = 0; i < n; ++i) {
        v.push_back(dp[i][k]);
        k -= distance(s[i], t[v.back()-'0']);
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s, k);

    return 0;
}
