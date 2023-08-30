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

std::vector<int> prepare(const std::vector<unsigned>& a, unsigned k)
{
    const size_t m = a.size();

    std::vector<std::vector<int>> dp(1 + m / 2, std::vector<int>(k, -1));
    dp[0][0] = 0;
    for (size_t i = 0; i < m; ++i) {
        std::vector<std::vector<int>> ndp = dp;
        for (size_t j = 0; j <= m / 2; ++j) {
            for (unsigned r = 0; r < k; ++r) {
                if (j < m / 2 && dp[j][r] != -1) {
                    const int s = dp[j][r] + a[i];
                    ndp[j+1][s % k] = std::max(ndp[j+1][s % k], s);
                }
            }
        }
        std::swap(dp, ndp);
    }

    std::vector<int> v(k, -1);
    for (size_t j = 0; j <= m / 2; ++j) {
        for (unsigned r = 0; r < k; ++r)
            v[r] = std::max(v[r], dp[j][r]);
    }
    return v;
}

void solve(const std::vector<std::vector<unsigned>>& a, unsigned k)
{
    const size_t n = a.size();

    std::vector<int> dp(k);
    for (size_t i = 0; i < n; ++i) {
        const std::vector<int> v = prepare(a[i], k);

        std::vector<int> ndp = dp;
        for (const int x : v) {
            if (x == -1)
                continue;

            for (unsigned r = 0; r < k; ++r) {
                if (dp[r] != -1) {
                    const int s = dp[r] + x;
                    ndp[s % k] = std::max(ndp[s % k], s);
                }
            }
        }
        std::swap(dp, ndp);
    }

    answer(dp[0]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    unsigned k;
    std::cin >> k;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a, k);

    return 0;
}
