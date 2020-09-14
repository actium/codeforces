#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(unsigned x, unsigned y, unsigned k)
{
    const integer c = k * (y + 1ull) - 1;

    answer((c + x - 2) / (x - 1) + k);
}

void test_case()
{
    unsigned x, y, k;
    std::cin >> x >> y >> k;

    solve(x, y, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

