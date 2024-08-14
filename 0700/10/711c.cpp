#include <iostream>
#include <vector>

using integer = unsigned long long;

constexpr integer oo = ~integer(0) >> 2;

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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& c, const std::vector<std::vector<unsigned>>& p, size_t k)
{
    const size_t n = p.size(), m = p[0].size();

    std::vector<std::vector<integer>> dp(1+k, std::vector<integer>(1+m, oo));
    if (c[0] != 0) {
        dp[1][c[0]] = 0;
    } else {
        for (size_t x = 1; x <= m; ++x)
            dp[1][x] = p[0][x-1];
    }

    for (size_t i = 1; i < n; ++i) {
        std::vector<std::vector<integer>> ndp(1+k, std::vector<integer>(1+m, oo));
        for (size_t j = 1; j <= k; ++j) {
            for (size_t q = 1; q <= m; ++q) {
                if (c[i] != 0) {
                    ndp[j][c[i]] = std::min(ndp[j][c[i]], q == c[i] ? dp[j][q] : dp[j-1][q]);
                } else {
                    for (size_t x = 1; x <= m; ++x)
                        ndp[j][x] = std::min(ndp[j][x], (x == q ? dp[j][q] : dp[j-1][q]) + p[i][x-1]);
                }
            }
        }

        std::swap(dp, ndp);
    }

    integer x = oo;
    for (size_t q = 1; q <= m; ++q)
        x = std::min(x, dp[k][q]);

    x != oo ? answer(x) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> c(n);
    std::cin >> c;

    std::vector<std::vector<unsigned>> p(n, std::vector<unsigned>(m));
    std::cin >> p;

    solve(c, p, k);

    return 0;
}
