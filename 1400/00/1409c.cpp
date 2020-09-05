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

void solve(unsigned n, unsigned x, unsigned y)
{
    unsigned p = 1;
    for (const unsigned d = y - x; p < d && (d % p != 0 || x + (n - 1) * p < y); ++p);

    std::vector<unsigned> a;
    for (unsigned q = y - std::min((y - 1) / p, n - 1) * p; n > 0; --n, q += p)
        a.push_back(q);

    answer(a);
}

void test_case()
{
    unsigned n, x, y;
    std::cin >> n >> x >> y;

    solve(n, x, y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

