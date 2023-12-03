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

void solve(unsigned n, unsigned k)
{
    const unsigned m = 2 * k - n;

    std::vector<unsigned> p(k);
    for (unsigned i = 1; i < m; ++i)
        p[i-1] = i;
    for (unsigned i = m; i <= k; ++i)
        p[i-1] = m + k - i;

    answer(p);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
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