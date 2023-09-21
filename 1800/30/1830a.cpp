#include <iostream>
#include <vector>

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

void solve(const std::vector<std::pair<unsigned, unsigned>>& e)
{
    const size_t m = e.size();

    std::vector<std::vector<std::pair<size_t, unsigned>>> g(m + 1);
    for (size_t i = 0; i < m; ++i) {
        const size_t u = e[i].first - 1, v = e[i].second - 1;
        g[u].emplace_back(v, i + 1);
        g[v].emplace_back(u, i + 1);
    }

    std::vector<unsigned> t(m + 1);
    t[0] = 1;

    std::vector<std::pair<size_t, unsigned>> q = { std::make_pair(0, 0) };
    for (size_t i = 0; i < q.size(); ++i) {
        const auto [u, x] = q[i];

        for (const std::pair<size_t, unsigned>& e : g[u]) {
            if (e.second != x) {
                t[e.first] = t[u] + (e.second < x);

                q.push_back(e);
            }
        }
    }

    unsigned v = 0;
    for (const unsigned x : t)
        v = std::max(v, x);

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> e(n - 1);
    std::cin >> e;

    solve(e);
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
