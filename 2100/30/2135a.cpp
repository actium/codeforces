#include <iostream>
#include <queue>
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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> dp(1+n);
    {
        std::vector<std::queue<size_t>> q(1+n);
        for (size_t i = 0; i < n; ++i) {
            dp[i+1] = dp[i];

            q[a[i]].push(i);

            if (q[a[i]].size() > a[i])
                q[a[i]].pop();

            if (q[a[i]].size() == a[i])
                dp[i+1] = std::max(dp[i+1], dp[q[a[i]].front()] + a[i]);
        }
    }

    answer(dp[n]);
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
