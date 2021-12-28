#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (n % 2 == 0)
        return answer(1 + (k - 1) % n);

    const unsigned d = (k - 1) / (n / 2);
    answer(1 + (k - 1 + d) % n);
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
