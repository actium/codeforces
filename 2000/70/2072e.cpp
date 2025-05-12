#include <iostream>
#include <vector>

using point_t = std::pair<unsigned, unsigned>;

void construct(unsigned x, unsigned y, unsigned k, std::vector<point_t>& p)
{
    if (k == 0)
        return;

    unsigned c = 1;
    while (c * (c + 1) / 2 <= k)
        ++c;

    do {
        p.emplace_back(x++, y);
        k -= --c;
    } while (c != 0);

    construct(x, y + 1, k, p);
}

void answer(const std::vector<point_t>& v)
{
    std::cout << v.size() << '\n';

    for (const point_t& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(unsigned k)
{
    std::vector<point_t> p;
    construct(0, 0, k, p);
    answer(p);
}

void test_case()
{
    unsigned k;
    std::cin >> k;

    solve(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
