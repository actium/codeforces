#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a1, unsigned a2, unsigned a3, unsigned a4)
{
    unsigned k = a1;
    if (k == 0)
        return answer(1);

    const unsigned d = std::min(a2, a3);
    k += 2 * d, a2 -= d, a3 -= d;

    const unsigned r = a2 + a3 + a4;
    answer(r <= a1 ? k + r : k + a1 + 1);
}

void test_case()
{
    unsigned a1, a2, a3, a4;
    std::cin >> a1 >> a2 >> a3 >> a4;

    solve(a1, a2, a3, a4);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
