#include <iostream>
#include <vector>

using point_t = std::pair<unsigned, unsigned>;

void answer(const std::vector<point_t>& v)
{
    std::cout << v.size() << '\n';

    for (const point_t& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(unsigned n, unsigned m)
{
    const size_t k = std::min(n, m) + 1;

    std::vector<point_t> p(k);
    for (size_t i = 0; i < k; ++i) {
        p[i].first = i;
        p[i].second = m - i;
    }

    answer(p);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
