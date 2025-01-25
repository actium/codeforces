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
    std::vector<unsigned> a(n);
    for (size_t i = 0; i < n; ++i)
        a[(x+i-1)%n] = i % 2;

    if (n % 2 != 0 || (y - x) % 2 == 0)
        a[x-1] = 2;

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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
