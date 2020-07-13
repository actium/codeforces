#include <algorithm>
#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(unsigned x, unsigned y, unsigned a, unsigned b)
{
    if (b >= 2 * a)
        return answer(integer(x + y) * a);

    const auto [min, max] = std::minmax(x, y);
    answer(1ull * min * b + integer(max - min) * a);
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    unsigned a, b;
    std::cin >> a >> b;

    solve(x, y, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

