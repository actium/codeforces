#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const auto& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(unsigned x, unsigned y, unsigned a, unsigned b)
{
    std::vector<std::pair<unsigned, unsigned>> o;
    for (unsigned i = std::max(a, b + 1); i <= x; ++i) {
        for (unsigned j = b; j < std::min(i, y+1); ++j)
            o.emplace_back(i, j);
    }

    answer(o);
}

int main()
{
    unsigned x, y, a, b;
    std::cin >> x >> y >> a >> b;

    solve(x, y, a, b);

    return 0;
}

