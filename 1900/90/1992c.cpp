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

void solve(unsigned n, unsigned m, unsigned)
{
    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n - m; ++i)
        p[i] = n - i;

    for (size_t i = 0; i < m; ++i)
        p[n-m+i] = i + 1;

    answer(p);
}

void test_case()
{
    unsigned n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);
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
