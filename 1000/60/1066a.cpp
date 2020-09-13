#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned d, unsigned p, unsigned l, unsigned r)
{
    const unsigned kd = d / p;
    const unsigned kl = (l - 1) / p;
    const unsigned kr = r / p;

    answer(kd - (kr - kl));
}

void test_case()
{
    unsigned d, p, l, r;
    std::cin >> d >> p >> l >> r;

    solve(d, p, l, r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

