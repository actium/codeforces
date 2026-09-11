#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, unsigned y, integer k)
{
    integer t = 0;
    while (2 * x <= y && k != 0) {
        t += y++ % x++;
        --k;
    }

    t += (y - x) * k;

    answer(t);
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    integer k;
    std::cin >> k;

    solve(x, y, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
