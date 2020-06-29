#include <iostream>

#include <cstdint>

using integer = uint64_t;

void answer(integer v)
{
    std::cout << v << '\n';
}

auto solve(integer n)
{
    integer count = 0;
    while (n != 0) {
        const size_t k = 64 - __builtin_clzll(n);
        count += (uint64_t(1) << k) - 1;
        n -= uint64_t(1) << (k - 1);
    }

    answer(count);
}

void test_case()
{
    integer n;
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

