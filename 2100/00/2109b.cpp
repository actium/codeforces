#include <iostream>

unsigned count(unsigned k)
{
    return k > 1 ? __builtin_clz(1) - __builtin_clz(k-1) + 1 : 0;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m, unsigned a, unsigned b)
{
    const unsigned k[2] = {
        1 + count(std::min(a, n-a+1)) + count(m),
        1 + count(std::min(b, m-b+1)) + count(n),
    };

    answer(std::min(k[0], k[1]));
}

void test_case()
{
    unsigned n, m, a, b;
    std::cin >> n >> m >> a >> b;

    solve(n, m, a, b);
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
