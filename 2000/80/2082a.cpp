#include <iostream>
#include <string>
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

unsigned sum(const std::vector<unsigned>& v)
{
    unsigned s = 0;
    for (const unsigned x : v)
        s += x;

    return s;
}

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    std::vector<unsigned> r(n), c(m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            r[i] ^= g[i][j] - '0';
            c[j] ^= g[i][j] - '0';
        }
    }

    answer(std::max(sum(r), sum(c)));
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);
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
