#include <iostream>
#include <set>
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

void answer(unsigned u, const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << ' ' << u << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& g, const std::vector<unsigned>& r)
{
    const size_t n = g.size(), k = r.size();

    std::set<std::pair<unsigned, size_t>> s;
    for (size_t i = 0; i < n; ++i)
        s.emplace(g[i].second, i);

    std::set<std::pair<unsigned, size_t>> t;
    for (size_t i = 0; i < k; ++i)
        t.emplace(r[i], i);

    std::vector<std::pair<size_t, size_t>> q;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        const auto jt = t.lower_bound(std::make_pair(g[it->second].first, 0));
        if (jt != t.end()) {
            q.emplace_back(it->second, jt->second);
            t.erase(jt);
        }
    }

    unsigned v = 0;
    for (const std::pair<size_t, size_t>& e : q)
        v += g[e.first].second;

    answer(v, q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> g(n);
    std::cin >> g;

    size_t k;
    std::cin >> k;

    std::vector<unsigned> r(k);
    std::cin >> r;

    solve(g, r);

    return 0;
}
