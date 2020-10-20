#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned x)
{
    const unsigned d = x % 10;

    unsigned k = d * 10;
    k -= 4 * (x < 1111);
    k -= 3 * (x < 111);
    k -= 2 * (x < 11);

    answer(k);
}

void test_case()
{
    unsigned x;
    std::cin >> x;

    solve(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

