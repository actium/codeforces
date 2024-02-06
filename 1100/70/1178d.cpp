#include <algorithm>
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
    std::vector<unsigned> p = { 2, 3 };
    for (unsigned i = 5; i < 1010; i += 2) {
        if (std::all_of(p.begin(), p.end(), [i](unsigned x) { return i % x != 0; }))
            p.push_back(i);
    }

    std::vector<std::pair<unsigned, unsigned>> e(n);
    for (size_t i = 0; i < n; ++i)
        e[i] = std::make_pair(i + 1, (i + 1) % n + 1);

    const unsigned k = *std::lower_bound(p.begin(), p.end(), n) - n;
    for (unsigned i = 0; i < k; ++i)
        e.emplace_back(i + 1, n - i - 1);

    answer(e);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
