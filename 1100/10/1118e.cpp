#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << "YES" << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (n > k * (k - 1ull))
        return no_answer();

    std::vector<std::pair<unsigned, unsigned>> p;
    p.emplace_back(1, 2);
    for (unsigned x = 1; p.size() < n; ) {
        if (p.back().second != x)
            p.emplace_back(p.back().first + 1, p.back().second == k ? 1 : p.back().second + 1);
        else
            p.emplace_back(1, ++x + 1);
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
