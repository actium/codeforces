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

void solve(size_t n, size_t m, size_t k)
{
    const size_t p = std::max(n / (m + 1), k);

    std::vector<unsigned> a(n);
    for (size_t i = 0; i < n; ++i)
        a[i] = i % p;

    answer(a);
}

void test_case()
{
    size_t n, m, k;
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
