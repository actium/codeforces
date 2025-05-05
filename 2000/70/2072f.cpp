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

std::vector<unsigned> construct(unsigned n, unsigned k)
{
    if (__builtin_popcount(n) == 1)
        return std::vector<unsigned>(n, k);

    const unsigned w = __builtin_clz(1) - __builtin_clz(n), m = n ^ 1 << w;

    std::vector<unsigned> v(n);
    {
        size_t i = 0, j = n;
        for (const unsigned x : construct(m, k)) {
            v[i++] = x;
            v[--j] = x;
        }
    }
    return v;
}

void solve(unsigned n, unsigned k)
{
    answer(construct(n, k));
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
