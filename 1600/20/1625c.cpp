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

void solve(const std::vector<unsigned>& d, const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = d.size();

    std::vector<std::vector<unsigned>> dp(n, std::vector<unsigned>(1 + k, ~0u));
    dp[0][0] = 0;
    for (size_t i = 0; i < n; ++i) {
        for (unsigned j = 0; j <= k && dp[i][j] != ~0u; ++j) {
            for (unsigned s = 0; s < n - i - 1 && s <= k - j; ++s) {
                const unsigned dx = d[i+s+1] - d[i], dt = dx * a[i];
                dp[i+s+1][j+s] = std::min(dp[i+s+1][j+s], dp[i][j] + dt); 
            }
        }
    }

    unsigned t = ~0u;
    for (const unsigned x : dp.back())
        t = std::min(t, x);

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned l, k;
    std::cin >> l >> k;

    std::vector<unsigned> d(n), a(n);
    std::cin >> d >> a;

    d.push_back(l);
    a.push_back(0);

    solve(d, a, k);

    return 0;
}
