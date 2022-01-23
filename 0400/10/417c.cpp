#include <iostream>
#include <vector>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (n < 2 * k + 1)
        return no_answer();

    std::vector<std::pair<size_t, size_t>> m;
    for (size_t i = 0; i < n; ++i) {
        for (unsigned j = 1; j <= k; ++j)
            m.emplace_back(i, (i + j) % n);
    }

    answer(m);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
