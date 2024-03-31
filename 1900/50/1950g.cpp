#include <iostream>
#include <map>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

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

unsigned search(const graph_t& g, size_t u, unsigned m, std::map<std::pair<unsigned, size_t>, unsigned>& memo)
{
    if (m == 0)
        return 0;

    const std::pair<unsigned, size_t> key = std::make_pair(m, u);

    auto it = memo.find(key);
    if (it == memo.end()) {
        unsigned k = 0;
        for (const size_t v : g[u]) {
            if ((m & 1 << v) != 0)
                k = std::max(k, 1 + search(g, v, m & ~(1 << v), memo));
        }

        it = memo.emplace(key, k).first;
    }

    return it->second;
}

void solve(const std::vector<std::pair<std::string, std::string>>& p)
{
    const size_t n = p.size(), m = 1 << n;

    graph_t g(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i != j && (p[i].first == p[j].first || p[i].second == p[j].second)) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    std::map<std::pair<unsigned, size_t>, unsigned> memo;

    unsigned k = 1;
    for (unsigned i = 1; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if ((i & 1 << j) != 0)
                k = std::max(k, 1 + search(g, j, i & ~(1 << j), memo));
        }
    }

    answer(n - k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<std::string, std::string>> p(n);
    std::cin >> p;

    solve(p);
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
