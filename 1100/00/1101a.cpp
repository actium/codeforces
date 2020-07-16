#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned l, unsigned r, unsigned d)
{
    answer(d < l ? d : (r / d + 1) * d);
}

void test_case()
{
    unsigned l, r, d;
    std::cin >> l >> r >> d;

    solve(l, r, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

