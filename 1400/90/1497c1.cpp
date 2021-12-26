#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (n % 2 == 1)
        return answer(n / 2, n / 2, 1);

    if (n % 4 == 0)
        return answer(n / 2, n / 4, n / 4);

    answer(n / 2 - 1, n / 2 - 1, 2);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
