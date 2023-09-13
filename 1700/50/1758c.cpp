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

void solve(unsigned n, unsigned x)
{
    if (n % x != 0)
        return no_answer();

    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = 1 + i;

    std::swap(p.front(), p[x-1]);
    std::swap(p[x-1], p.back());

    for (size_t i = x; i < n; ++i) {
        if (p[i] % x == 0 && p[x-1] % (i + 1) == 0) {
            std::swap(p[x-1], p[i]);
            x = i + 1;
        }
    }

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
