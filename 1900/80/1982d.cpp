#include <iostream>
#include <numeric>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& h, const std::vector<std::string>& t, size_t k)
{
    using integer = unsigned long long;

    const size_t n = h.size(), m = h[0].size();

    integer s[2] = {};
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            s[t[i][j]-'0'] += h[i][j];
    }

    const integer d = std::max(s[0], s[1]) - std::min(s[0], s[1]);
    if (d == 0)
        return answer(true);

    std::vector<std::vector<unsigned>> ps(1+n, std::vector<unsigned>(1+m));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            ps[i+1][j+1] = ps[i][j+1] + ps[i+1][j] - ps[i][j] + (t[i][j] - '0');
    }

    unsigned g = 0;
    for (size_t i = k; i <= n; ++i) {
        for (size_t j = k; j <= m; ++j) {
            const unsigned c1 = ps[i][j] - ps[i-k][j] - ps[i][j-k] + ps[i-k][j-k], c2 = k * k - c1;
            g = std::gcd(g, std::max(c1, c2) - std::min(c1, c2));
        }
    }

    answer(g != 0 && d % g == 0);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::vector<unsigned>> h(n, std::vector<unsigned>(m));
    std::cin >> h;

    std::vector<std::string> t(n);
    std::cin >> t;

    solve(h, t, k);
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
