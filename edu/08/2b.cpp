#include <algorithm>
#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << "YES" << '\n';

    std::cout << v.size() << '\n';
    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (n <= k || n * k % 2 != 0)
        return no_answer();

    std::vector<std::pair<unsigned, unsigned>> p;
    for (unsigned i = 1; i <= n; ++i)
        p.emplace_back(k, i);

    std::vector<std::pair<unsigned, unsigned>> e;
    while (!p.empty()) {
        const size_t k = p[0].first;
        for (size_t i = 1; i <= k; ++i) {
            e.emplace_back(p[0].second, p[i].second);
            --p[0].first;
            --p[i].first;
        }

        std::sort(p.begin(), p.end(), std::greater<std::pair<unsigned, unsigned>>());
        while (!p.empty() && p.back().first == 0)
            p.pop_back();
    }

    answer(e);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
