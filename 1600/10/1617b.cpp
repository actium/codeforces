#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned n)
{
    if (n % 2 == 0)
        return answer(2, n - 3, 1);

    const unsigned d = (n % 4 == 3);
    answer(n / 2 - 1 - d, n / 2 + 1 + d, 1);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
