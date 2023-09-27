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

void solve(unsigned x, unsigned y, unsigned n)
{
    std::vector<unsigned> a(n);
    for (size_t i = n, d = 0; i-- > 0; ++d) {
        if (y < x + d)
            return no_answer();

        y -= d;
        a[i] = y;
    }
    a[0] = x;

    answer(a);
}

void test_case()
{
    unsigned x, y, n;
    std::cin >> x >> y >> n;

    solve(x, y, n);
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
