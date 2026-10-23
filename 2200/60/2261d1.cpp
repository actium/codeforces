#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(unsigned n)
{
    std::vector<std::pair<unsigned, unsigned>> p;
    if (n != 1) {
        p.emplace_back(1, (n + 1) / 2);

        for (unsigned u = 2, v = n - 1; u <= v; ++u, --v)
            p.emplace_back(u, v);
    }

    answer(p);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n);
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
