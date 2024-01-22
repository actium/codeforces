#include <iostream>
#include <numeric>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a)
{
    const unsigned b = ~a & (~0u >> __builtin_clz(a));
    if (b != 0)
        return answer(std::gcd(a ^ b, a & b));

    unsigned g = 1;
    for (unsigned i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            const unsigned b = a / i;
            g = std::max(g, std::gcd(a ^ b, a & b));
        }
    }

    answer(g);
}

void test_case()
{
    unsigned a;
    std::cin >> a;

    solve(a);
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
