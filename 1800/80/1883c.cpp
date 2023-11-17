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

void solve(std::vector<unsigned>& a, unsigned k)
{
    std::vector<unsigned> dp(k);
    for (unsigned d = 0; d < k; ++d)
        dp[(a[0] + d) % k] = d;

    for (auto it = a.begin() + 1; it != a.end(); ++it) {
        std::vector<unsigned> t = dp;
        for (unsigned i = 0; i < k; ++i) {
            for (unsigned d = 0; d < k; ++d)
                t[i * (*it + d) % k] = std::min(t[i * (*it + d) % k], dp[i] + d);
        }
        dp = std::move(t);
    }

    answer(dp[0]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
