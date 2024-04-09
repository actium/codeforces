#include <iostream>
#include <string>
#include <vector>

constexpr unsigned K = 11, M = 1 << K;
constexpr unsigned powers_of_3[1+K] = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147 };

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Tower {
    unsigned r;
    unsigned c;
    unsigned p;
};

std::istream& operator >>(std::istream& input, Tower& t)
{
    return input >> t.r >> t.c >> t.p;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& g, const std::vector<Tower>& t)
{
    const size_t n = g.size(), m = g[0].size(), k = t.size();

    const auto coverage = [&](const Tower& t) {
        std::vector<unsigned> c(1 + K);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (g[i][j] != '#')
                    continue;

                for (unsigned r = 1; r <= K; ++r) {
                    const int dr = t.r - (1 + i), dc = t.c - (1 + j);
                    c[r] += (dr * dr + dc * dc <= r * r);
                }
            }
        }
        return c;
    };

    std::vector<unsigned> dp(M);
    for (size_t i = 0; i < k; ++i) {
        const std::vector<unsigned> c = coverage(t[i]);

        std::vector<unsigned> ndp = dp;
        for (size_t j = 0; j < M; ++j) {
            for (unsigned r = 1; r <= K; ++r) {
                const unsigned d = t[i].p * c[r];
                if (d > powers_of_3[r]) {
                    const unsigned u = j | 1 << r - 1, v = u ^ (1 << r - 1);
                    ndp[u] = std::max(ndp[u], dp[v] + d - powers_of_3[r]);
                }
            }
        }

        std::swap(dp, ndp);
    }

    unsigned v = 0;
    for (const unsigned x : dp)
        v = std::max(v, x);

    answer(v);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::string> g(n);
    std::cin >> g;

    std::vector<Tower> t(k);
    std::cin >> t;

    solve(g, t);
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
