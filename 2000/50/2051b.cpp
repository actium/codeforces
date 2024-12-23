#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned a, unsigned b, unsigned c)
{
    const unsigned d = a + b + c;

    unsigned k = n / d * 3;
    n %= d;

    k += (n > a + b);
    k += (n > a);
    k += (n > 0);

    answer(k);
}

void test_case()
{
    unsigned n, a, b, c;
    std::cin >> n >> a >> b >> c;

    solve(n, a, b, c);
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
