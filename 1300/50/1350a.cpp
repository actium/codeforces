#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, size_t k)
{
    if (n % 2 == 0)
        return answer(n + 2 * k);

    unsigned x = 3;
    while (x < n && n % x != 0)
        x += 2;

    answer(n + 2 * (k - 1) + x);
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

