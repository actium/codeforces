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

void solve(unsigned n, unsigned k)
{
    std::vector<unsigned> p(n);

    int x = 0, d = k;
    for (unsigned i = n; i > 0; --i) {
        p[x] = i;
        x += d;
        if (x < 0 || x >= n) {
            x -= d - 1;
            d = -d;
        }
        if (x == n)
            x -= k;
    }

    answer(p);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
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
