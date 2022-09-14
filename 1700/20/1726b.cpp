#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(unsigned n, unsigned m)
{
    if (n > m)
        return no_answer();

    if (n % 2 == 0 && m % 2 == 1)
        return no_answer();

    std::vector<unsigned> p(n, 1);
    if (n % 2 == 1) {
        p[n-1] = m - (n - 1);
    } else {
        p[n-2] = (m - (n - 2)) / 2;
        p[n-1] = (m - (n - 2)) / 2;
    }
    answer(p);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
