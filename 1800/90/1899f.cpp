#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(unsigned n, const std::vector<unsigned>& d)
{
    std::vector<unsigned> c[3] = { {1}, {1}, {1} };

    const auto make_edge = [&](size_t x, unsigned v) {
        std::cout << c[x].back() << ' ' << v << '\n';

        c[x].push_back(v);
    };

    make_edge(2, n);
    for (unsigned i = 2; i < n; ++i)
        make_edge(1, i);

    const auto make_operation = [&](size_t v, size_t x) {
        std::cout << c[v][x] << ' ' << c[v][x-1] << ' ' << c[v^1].back() << '\n';

        c[v^1].insert(c[v^1].end(), c[v].begin() + x, c[v].end());
        c[v].erase(c[v].begin() + x, c[v].end());
    };

    for (const unsigned q : d) {
        if (c[0].size() == q || c[1].size() == q) {
            std::cout << "-1 -1 -1" << '\n';
            continue;
        }

        size_t v = (c[0].size() > c[1].size() ? 0 : 1), x = q;
        if (q >= c[v].size()) {
            x = c[v^1].size() - (q - c[v].size());
            v ^= 1;
        }

        make_operation(v, x);
    }
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> d(q);
    std::cin >> d;

    solve(n, d);
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
