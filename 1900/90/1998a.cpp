#include <iostream>
#include <vector>

void answer(const std::vector<std::pair<int, int>>& v)
{
    for (const std::pair<int, int>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(int x, int y, unsigned k)
{
    std::vector<std::pair<int, int>> p(k, { x, y });
    for (unsigned i = 1; i < k; i += 2) {
        p[i-0].first += i + 1;
        p[i-1].first -= i + 1;
    }

    answer(p);
}

void test_case()
{
    int x, y;
    std::cin >> x >> y;

    unsigned k;
    std::cin >> k;

    solve(x, y, k);
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
