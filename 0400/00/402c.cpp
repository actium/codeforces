#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(unsigned n, unsigned p)
{
    std::vector<std::pair<unsigned, unsigned>> e;
    for (unsigned i = 1; i < n; ++i) {
        for (unsigned j = i + 1; j <= n; ++j)
            e.emplace_back(i, j);
    }

    e.resize(2 * n + p);

    answer(e);
}

void test_case()
{
    unsigned n, p;
    std::cin >> n >> p;

    solve(n, p);
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
