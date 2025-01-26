#include <iostream>
#include <vector>

using integer = unsigned long long;

integer shift(unsigned k)
{
    return 1ull << k - 1;
}

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

void solve(unsigned n, integer k)
{
    std::vector<unsigned> p(n);
    for (size_t i = 0, j = n, x = 1; x <= n; ++x) {
        if (x == n || n - x > 60 || k <= shift(n - x)) {
            p[i++] = x;
        } else {
            p[--j] = x;
            k -= shift(n - x);
        }
    }

    if (k == 1)
        return answer(p);

    no_answer();
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    integer k;
    std::cin >> k;

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
