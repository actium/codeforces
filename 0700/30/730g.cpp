#include <iostream>
#include <map>
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

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = r.size();

    std::vector<std::pair<unsigned, unsigned>> p(n);
    {
        std::map<unsigned, unsigned> s;
        s.emplace(1, ~0u);
        for (size_t i = 0; i < n; ++i) {
            auto it = s.begin();
            while (it->second - it->first < r[i].second)
                ++it;

            auto jt = it;
            while (jt != s.end() && !(jt->first <= r[i].first && r[i].first + r[i].second <= jt->second))
                ++jt;

            if (jt != s.end()) {
                p[i] = { r[i].first, r[i].first + r[i].second - 1 };

                const auto x = *jt;
                s.erase(jt);
                s.emplace(x.first, r[i].first);
                s.emplace(r[i].first + r[i].second, x.second);
            } else {
                p[i] = { it->first, it->first + r[i].second - 1 };

                const auto x = *it;
                s.erase(it);
                s.emplace(x.first + r[i].second, x.second);
            }
        }
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}
