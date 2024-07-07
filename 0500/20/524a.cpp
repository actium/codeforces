#include <iostream>
#include <map>
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

void answer(const std::map<unsigned, std::set<unsigned>>& v)
{
    for (const auto& e : v) {
        std::cout << e.first << ':' << ' ' << e.second.size();

        for (const unsigned x : e.second)
            std::cout << ' ' << x;

        std::cout << '\n';
    }
}

unsigned intersect(const std::set<unsigned>& u, const std::set<unsigned>& v)
{
    unsigned k = 0;
    for (const unsigned x : u)
        k += v.count(x);

    return k;
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& f, unsigned k)
{
    std::map<unsigned, std::set<unsigned>> g;
    for (const std::pair<unsigned, unsigned>& e : f) {
        g[e.first].insert(e.second);
        g[e.second].insert(e.first);
    }

    std::map<unsigned, std::set<unsigned>> p;
    for (auto it = g.begin(); it != g.end(); ++it) {
        p[it->first];

        for (auto jt = g.begin(); jt != g.end(); ++jt) {
            if (jt == it || it->second.count(jt->first) != 0)
                continue;

            const unsigned q = intersect(it->second, jt->second);
            if (100 * q >= k * it->second.size())
                p[it->first].insert(jt->first);
        }
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t m;
    std::cin >> m;

    unsigned k;
    std::cin >> k;

    std::vector<std::pair<unsigned, unsigned>> f(m);
    std::cin >> f;

    solve(f, k);

    return 0;
}
