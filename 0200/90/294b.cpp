#include <iostream>
#include <vector>

constexpr unsigned W = 200;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(const std::vector<std::pair<unsigned, unsigned>>& d)
{
    const size_t n = d.size();

    std::vector<std::vector<unsigned>> dp(1+W, std::vector<unsigned>(1+W));
    for (const auto& e : d) {
        std::vector<std::vector<unsigned>> ndp = dp;

        ndp[e.first][0] = std::max(ndp[e.first][0], 1u);
        for (unsigned i = e.first; i <= W; ++i) {
            for (unsigned j = 0; j <= W; ++j) {
                if (dp[i-e.first][j] != 0)
                    ndp[i][j] = std::max(ndp[i][j], dp[i-e.first][j] + 1);
            }
        }

        ndp[0][e.second] = std::max(ndp[0][e.second], 1u);
        for (unsigned i = 0; i <= W; ++i) {
            for (unsigned j = e.second; j <= W; ++j) {
                if (dp[i][j-e.second] != 0)
                    ndp[i][j] = std::max(ndp[i][j], dp[i][j-e.second] + 1);
            }
        }

        std::swap(dp, ndp);
    }

    for (unsigned i = 1; i < W; ++i) {
        for (unsigned j = 0; j <= i; ++j) {
            if (dp[i][j] == n)
                return answer(i);
        }
    }

    answer(W);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> d(n);
    std::cin >> d;

    solve(d);

    return 0;
}
