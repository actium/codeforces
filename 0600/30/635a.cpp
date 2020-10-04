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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(size_t r, size_t c, size_t k, const std::vector<std::pair<unsigned, unsigned>>& p)
{
    std::vector<std::vector<unsigned>> dp(r+1, std::vector<unsigned>(c+1));

    for (const auto& x : p)
        dp[x.first][x.second] = 1;

    for (size_t i = 1; i <= r; ++i) {
        for (size_t j = 1; j <= c; ++j) {
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    unsigned m = 0;
    for (size_t r1 = 1; r1 <= r; ++r1) {
        for (size_t c1 = 1; c1 <= c; ++c1) {
            for (size_t r2 = r1; r2 <= r; ++r2) {
                for (size_t c2 = c1; c2 <= c; ++c2) {
                    if (dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1] >= k)
                        ++m;
                }
            }
        }
    }

    answer(m);
}

int main()
{
    size_t r, c, n, k;
    std::cin >> r >> c >> n >> k;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(r, c, k, p);

    return 0;
}

