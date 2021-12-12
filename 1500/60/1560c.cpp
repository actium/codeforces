#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned k)
{
    unsigned r = 1, c = 1, x = 1;
    for (unsigned d = 0; x + d < k; ++d, x += 2 * d)
        ++r, ++c;

    while (x > k)
        --r, --x;

    while (x < k)
        --c, ++x;

    answer(r, c);
}

void test_case()
{
    unsigned k;
    std::cin >> k;

    solve(k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
