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

void solve(std::vector<unsigned>& p, unsigned n)
{
    if (n == 2)
        p[0] = 1;

    if (n < 3)
        return;

    unsigned x = 0;
    while (x * x < n)
        ++x;

    const unsigned d = (x * x - (n - 1)) % n;
    for (size_t i = 0; d + i < n; ++i)
        p[d + i] = n - 1 - i;

    solve(p, d);
}

void solve(unsigned n)
{
    std::vector<unsigned> p(n);
    solve(p, n);
    answer(p);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
