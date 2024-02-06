#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    unsigned t;
    int x;
    int y;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.t >> q.x >> q.y;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool search(const graph_t& g, size_t s, size_t t, std::vector<bool>& v)
{
    if (s == t)
        return true;

    v[s] = true;
    for (const size_t x : g[s]) {
        if (!v[x] && search(g, x, t, v))
            return true;
    }

    return false;
}

void solve(const std::vector<Query>& r)
{
    const size_t n = r.size();

    std::vector<std::pair<int, int>> s;

    graph_t g(n);
    for (const Query& q : r) {
        if (q.t == 1) {
            const size_t k = s.size();
            for (size_t i = 0; i < k; ++i) {
                if (q.x < s[i].first && s[i].first < q.y || q.x < s[i].second && s[i].second < q.y)
                    g[i].push_back(k);

                if (s[i].first < q.x && q.x < s[i].second || s[i].first < q.y && q.y < s[i].second)
                    g[k].push_back(i);
            }
            s.emplace_back(q.x, q.y);
        } else {
            std::vector<bool> v(n);
            answer(search(g, q.x-1, q.y-1, v));
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    std::vector<Query> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}
