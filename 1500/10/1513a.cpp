#include <iostream>
#include <numeric>
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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(size_t n, size_t k)
{
    if (k >= (n + 1) / 2)
        return no_answer();

    std::vector<unsigned> a(n);
    std::iota(a.begin(), a.end(), 1);
    for (size_t i = 2; i < n && k > 0; i += 2, --k)
        std::swap(a[i-1], a[i]);

    answer(a);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
