#include <algorithm>
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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size(), m = r.size();

    std::map<unsigned, std::vector<size_t>> p;
    for (size_t i = 0; i < n; ++i)
        p[a[i]].push_back(i);

    std::vector<unsigned> v(m);
    for (size_t i = 0; i < m; ++i) {
        std::vector<size_t> x;
        for (auto it = p.rbegin(); x.size() < r[i].first; ++it)
            x.insert(x.end(), it->second.begin(), it->second.end());

        std::sort(x.begin(), x.begin() + r[i].first);

        v[i] = a[x[r[i].second-1]];
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(a, r);

    return 0;
}
