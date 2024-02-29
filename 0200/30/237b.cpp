#include <iostream>
#include <vector>

using location_t = std::pair<size_t, size_t>;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<location_t, location_t>>& v)
{
    std::cout << v.size() << '\n';
    for (const std::pair<location_t, location_t>& x : v) {
        std::cout << 1 + x.first.first << ' ' << 1 + x.first.second << ' ';
        std::cout << 1 + x.second.first << ' ' << 1 + x.second.second << '\n';
    }
}

void solve(std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();

    location_t p[2501];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < a[i].size(); ++j)
            p[a[i][j]] = std::make_pair(i, j);
    }

    std::vector<std::pair<location_t, location_t>> r;
    for (size_t i = 0, x = 1; i < n; ++i) {
        for (size_t j = 0; j < a[i].size(); ++j, ++x) {
            const location_t q = std::make_pair(i, j);
            if (p[x] == q)
                continue;

            r.emplace_back(q, p[x]);
            a[p[x].first][p[x].second] = a[i][j];
            p[a[i][j]] = p[x];
        }
    }

    answer(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<size_t> c(n);
    std::cin >> c;

    std::vector<std::vector<unsigned>> a(n);
    for (size_t i = 0; i < n; ++i)
        a[i].resize(c[i]);

    std::cin >> a;

    solve(a);

    return 0;
}
