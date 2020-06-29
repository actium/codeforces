#include <iostream>
#include <set>

using point_t = std::pair<size_t, size_t>;

void answer(const std::set<point_t>& v)
{
    std::cout << v.size() << '\n';

    for (const auto& p : v) {
        std::cout << p.first << ' ' << p.second << '\n';
    }
}

void solve(size_t n)
{
    std::set<point_t> x;
    for (size_t i = 0; i < n; ++i) {
        x.emplace(i, i);
        x.emplace(i, i+1);
        x.emplace(i+1, i);
        x.emplace(i+1, i+1);
        x.emplace(i+1, i+2);
        x.emplace(i+2, i+1);
        x.emplace(i+2, i+2);
    }

    answer(x);
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

