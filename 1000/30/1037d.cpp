#include <iostream>
#include <set>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const graph_t& g, const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<bool> v(n);
    v[0] = true;
    for (size_t i = 0, j = 1; i < n; ++i) {
        std::set<size_t> q;
        for (const size_t u : g[a[i]-1]) {
            if (!v[u]) {
                q.insert(u);
                v[u] = true;
            }
        }

        for (size_t k = q.size(); k != 0; --k) {
            if (j == n || q.count(a[j++] - 1) == 0)
                return answer(false);
        }
    }

    answer(true);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(g, a);

    return 0;
}
