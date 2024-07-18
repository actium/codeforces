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

void solve(const std::vector<unsigned>& a, unsigned h, unsigned l, unsigned r)
{
    const size_t n = a.size();

    std::vector<unsigned> dp(1+n);
    {
        unsigned t = 0;
        for (size_t i = 0; i < n; ++i) {
            t += a[i];

            std::vector<unsigned> ndp(1+n);
            for (unsigned k = 0; k <= i; ++k) {
                const unsigned p = (t - k) % h, q = (t - k - 1) % h;

                ndp[k] = std::max(ndp[k], dp[k] + (p >= l && p <= r));
                ndp[k+1] = std::max(ndp[k+1], dp[k] + (q >= l && q <= r));
            }

            std::swap(dp, ndp);
        }
    }

    unsigned x = 0;
    for (size_t i = 0; i <= n; ++i)
        x = std::max(x, dp[i]);

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned h, l, r;
    std::cin >> h >> l >> r;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, h, l, r);

    return 0;
}
