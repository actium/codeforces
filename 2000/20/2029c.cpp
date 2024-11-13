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

unsigned next(unsigned x, unsigned q)
{
    return x - (q < x) + (q > x);
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> dp(3);
    dp[0] = next(0, a[0]);
    for (size_t i = 1; i < n; ++i) {
        dp = {
            next(dp[0], a[i]),
            std::max(dp[0], dp[1]),
            std::max(next(dp[1], a[i]), next(dp[2], a[i]))
        };
    }

    answer(std::max(dp[1], dp[2]));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
