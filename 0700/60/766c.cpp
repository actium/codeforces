#include <array>
#include <iostream>
#include <vector>

constexpr unsigned M = 1'000'000'007;

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
    std::cout << z << '\n';
}

struct State {
    unsigned number_of_ways = 0;
    unsigned min_partition_count = ~0u >> 1;
    unsigned max_partition_size = 0;
};

void solve(const std::string& s, const std::array<unsigned, 26>& a)
{
    const size_t n = s.length();

    std::vector<std::array<unsigned, 26>> pf(1+n);
    for (size_t i = 0; i < n; ++i) {
        pf[i+1] = pf[i];
        ++pf[i+1][s[i]-'a'];
    }

    const auto check = [&](size_t begin, size_t end) {
        for (size_t i = 0; i < 26; ++i) {
            if (pf[end][i] - pf[begin][i] != 0 && end - begin > a[i])
                return false;
        }
        return true;
    };

    std::vector<std::vector<State>> dp(1+n, std::vector<State>(1+n));
    dp[0][0] = { 1, 0, 0 };
    for (size_t i = 1; i <= n; ++i) {
        dp[i][1].number_of_ways = dp[i-1][0].number_of_ways;
        dp[i][1].min_partition_count = dp[i-1][0].min_partition_count + 1;
        dp[i][1].max_partition_size = 1;

        for (size_t k = 2; k <= i; ++k) {
            if (check(i - k, i)) {
                dp[i][k].number_of_ways = dp[i-1][k-1].number_of_ways;
                dp[i][k].min_partition_count = dp[i-1][k-1].min_partition_count;
                dp[i][k].max_partition_size = std::max<unsigned>(dp[i-1][k-1].max_partition_size, k);
            }

            dp[i][1].number_of_ways = (dp[i][1].number_of_ways + dp[i-1][k-1].number_of_ways) % M;
            dp[i][1].min_partition_count = std::min(dp[i][1].min_partition_count, dp[i-1][k-1].min_partition_count + 1);
            dp[i][1].max_partition_size = std::max(dp[i][1].max_partition_size, dp[i-1][k-1].max_partition_size);
        }
    }

    State result;
    for (size_t k = 1; k <= n; ++k) {
        result.number_of_ways = (result.number_of_ways + dp[n][k].number_of_ways) % M;
        result.min_partition_count = std::min(result.min_partition_count, dp[n][k].min_partition_count);
        result.max_partition_size = std::max(result.max_partition_size, dp[n][k].max_partition_size);
    }

    answer(result.number_of_ways, result.max_partition_size, result.min_partition_count);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::array<unsigned, 26> a;
    std::cin >> a;

    solve(s, a);

    return 0;
}
