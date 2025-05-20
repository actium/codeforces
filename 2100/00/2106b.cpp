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

void solve(unsigned n, unsigned x)
{
    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    if (x < n)
        std::swap(p[x], p.back());

    answer(p);
}

void test_case()
{
    unsigned n, x;
    std::cin >> n >> x;

    solve(n, x);
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
