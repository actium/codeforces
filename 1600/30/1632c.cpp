#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    unsigned k = b - a;
    for (unsigned x = a; x <= b; x = (x | x - 1) + 1) {
        for (unsigned y = b; y <= 2 * b - a; ++y)
            k = std::min(k, x - (a + b) + (x | y) + 1);
    }

    answer(k);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
