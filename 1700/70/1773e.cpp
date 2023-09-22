#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& t)
{
    using index_t = std::pair<size_t, size_t>;

    const size_t n = t.size();

    std::vector<index_t> p;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < t[i].size(); ++j)
            p.emplace_back(i, j);
    }

    std::sort(p.begin(), p.end(), [&t](const index_t& lhs, const index_t& rhs) {
        return t[lhs.first][lhs.second] > t[rhs.first][rhs.second];
    });

    std::vector<std::vector<size_t>> b(n);
    for (size_t i = 0; i < n; ++i)
        b[i].resize(t[i].size());

    for (size_t i = 0; i < p.size(); ++i)
        b[p[i].first][p[i].second] = i;

    unsigned s = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 1; j < b[i].size(); ++j)
            s += (b[i][j-1] != b[i][j] + 1);
    }

    answer(s, n + s - 1);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> t(n);
    for (size_t i = 0; i < n; ++i) {
        size_t k;
        std::cin >> k;

        t[i].resize(k);
        std::cin >> t[i];
    }

    solve(t);

    return 0;
}
