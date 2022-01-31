#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

unsigned q[1001];

constexpr void initialize()
{
    constexpr auto update = [](size_t i, size_t j) {
        if (j <= 1000 && (q[j] == 0 || q[i] + 1 < q[j]))
            q[j] = q[i] + 1;
    };

    for (unsigned i = 1; i <= 1000; ++i) {
        for (unsigned j = 1; j <= i; ++j)
            update(i, i + i / j);
    }
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& b, const std::vector<unsigned>& c, size_t k)
{
    const size_t n = b.size();

    k = std::min(k, *std::max_element(std::begin(q), std::end(q)) * n);

    std::vector<integer> dp(1 + k);
    for (size_t i = 0; i < n; ++i) {
        const unsigned d = q[b[i]];
        if (d == 0) {
            for (size_t j = 0; j <= k; ++j)
                dp[j] += c[i];
        } else {
            for (unsigned j = k; j >= d; --j)
                dp[j] = std::max(dp[j], dp[j-d] + c[i]);
        }
    }

    answer(*std::max_element(dp.cbegin(), dp.cend()));
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> b(n), c(n);
    std::cin >> b >> c;

    solve(b, c, k);
}

int main()
{
    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
