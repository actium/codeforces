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

void solve(size_t n, size_t k)
{
    std::vector<unsigned> p(n);
    for (size_t i = 0, q = 1; i < n; ++i, ++q)
        p[i] = (q % k == 0 ? q / k : 1 + n - q + q / k);

    answer(p);
}

void test_case()
{
    size_t n, k;
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
