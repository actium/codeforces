#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned l, unsigned r, unsigned a)
{
    const unsigned b = r / a;
    if (b * a < l + 1)
        return answer(b + r % a);

    answer(std::max(b + r % a, b - 1 + a - 1));
}

void test_case()
{
    unsigned l, r, a;
    std::cin >> l >> r >> a;

    solve(l, r, a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
