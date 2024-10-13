#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

constexpr integer oo = ~integer(0);

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, std::vector<std::vector<unsigned>>& d)
{
    const size_t m = d.size();

    for (size_t i = 0; i < m; ++i)
        std::sort(d[i].begin(), d[i].end(), std::greater<unsigned>());

    integer w = oo;
    for (unsigned b = 0; b < n; ++b) {
        integer c = 0;
        for (size_t i = 1; i < m; ++i) {
            for (size_t j = b; j < d[i].size(); ++j)
                c += d[i][j];
        }

        std::vector<unsigned> q;
        for (size_t i = 1; i < m; ++i)
            q.insert(q.end(), d[i].begin(), d[i].begin() + std::min<size_t>(b, d[i].size()));

        if (n - q.size() <= b) {
            std::sort(q.begin(), q.end());
            for (unsigned i = 0; i <= b - (n - q.size()); ++i)
                c += q[i];
        }

        w = std::min(w, c);
    }

    answer(w);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    size_t m;
    std::cin >> m;

    std::vector<std::vector<unsigned>> d(m);
    for (size_t i = 0; i < n; ++i) {
        unsigned p, c;
        std::cin >> p >> c;

        d[p-1].push_back(c);
    }

    solve(n, d);

    return 0;
}