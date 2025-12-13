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

void solve(unsigned n, unsigned l, unsigned r)
{
    std::vector<unsigned> p(1+n);
    for (size_t i = 1; i <= n; ++i)
        p[i] = i;

    p[r] = l - 1;

    std::vector<unsigned> a(n);
    for (size_t i = 0; i < n; ++i)
        a[i] = p[i+1] ^ p[i];

    answer(a);
}

void test_case()
{
    unsigned n, l, r;
    std::cin >> n >> l >> r;

    solve(n, l, r);
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
