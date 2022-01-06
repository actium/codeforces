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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    if (a + b > n - 2)
        return no_answer();

    if (std::max(a, b) - std::min(a, b) > 1)
        return no_answer();

    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = 1+i;

    if (a == b) {
        for (unsigned k = 0; k < a; ++k) {
            const size_t i = 2 + k * 2;
            if (i < n)
                std::swap(p[i], p[i-1]);
        }
    }

    if (a > b) {
        for (unsigned k = 0; k < a-1; ++k) {
            const size_t i = 2 + k * 2;
            if (i < n)
                std::swap(p[i], p[i-1]);
        }

        const size_t d = 2 * a - 1;
        if (d < n)
            std::reverse(p.begin() + d, p.end());
    }

    if (a < b) {
        for (unsigned k = 0; k < b; ++k) {
            const size_t i = 1 + k * 2;
            if (i < n)
                std::swap(p[i], p[i-1]);
        }
    }

    answer(p);
}

void test_case()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
