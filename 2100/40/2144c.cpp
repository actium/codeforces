#include <iostream>
#include <vector>

constexpr unsigned M = 998244353;

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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    unsigned dp[2] = { 1, 1 };
    for (size_t i = 1; i < n; ++i) {
        unsigned dq[2] = {};

        if (a[i] >= a[i-1] && b[i] >= b[i-1]) {
            dq[0] = (dq[0] + dp[0]) % M;
            dq[1] = (dq[1] + dp[1]) % M;
        }
        if (a[i] >= b[i-1] && b[i] >= a[i-1]) {
            dq[0] = (dq[0] + dp[1]) % M;
            dq[1] = (dq[1] + dp[0]) % M;
        }

        dp[0] = dq[0];
        dp[1] = dq[1];
    }

    answer((dp[0] + dp[1]) % M);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
