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
    std::vector<unsigned> p(n);
    for (size_t i = 1; i < n; ++i)
        p[i-1] = i ^ 1;

    p[n-1] = 1;

    std::vector<bool> v(1+n);
    for (size_t i = 0; i < n; ++i)
        v[p[i]] = true;

    for (p[0] = 1; v[p[0]]; ++p[0]);

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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
