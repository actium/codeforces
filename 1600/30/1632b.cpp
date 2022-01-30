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

void solve(unsigned n)
{
    const unsigned x = 1 << 31 - __builtin_clz(n - 1);

    std::vector<unsigned> p;
    for (unsigned i = x; i > 0; --i)
        p.push_back(i-1);

    for (unsigned i = x; i < n; ++i)
        p.push_back(i);

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
