#include <iostream>
#include <vector>

void answer(unsigned u, const std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(unsigned n)
{
    std::vector<unsigned> p;
    for (unsigned i = 1; i <= n; ++i) {
        if (i  % 2 == 0)
            continue;
        
        for (unsigned x = i; x <= n; x *= 2)
            p.push_back(x);
    }

    answer(2, p);
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
