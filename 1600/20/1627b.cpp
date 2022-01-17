#include <algorithm>
#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n, unsigned m)
{
    std::vector<unsigned> d;
    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = 1; j <= m; ++j)
            d.push_back(std::max(i - 1, n - i) + std::max(j - 1, m - j));
    }

    std::sort(d.begin(), d.end());

    answer(d);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
