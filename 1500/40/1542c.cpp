#include <iostream>

using integer = unsigned long long;

constexpr unsigned M = 1000000007;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n)
{
    constexpr integer t[20][2] = {
        { 5342931457063200, 41 },
        { 144403552893600, 37 },
        { 72201776446800, 32 },
        { 2329089562800, 31 },
        { 80313433200, 29 },
        { 26771144400, 27 },
        { 5354228880, 25 },
        { 232792560, 23 },
        { 12252240, 19 },
        { 720720, 17 },
        { 360360, 16 },
        { 27720, 13 },
        { 2520, 11 },
        { 840, 9 },
        { 420, 8 },
        { 60, 7 },
        { 12, 5 },
        { 6, 4 },
        { 2, 3 },
        { 1, 2 },
    };

    integer k = 0, s = 0;
    for (size_t i = 0; i < 20; ++i) {
        const integer c = n / t[i][0] - k;
        s = (s + c * t[i][1]) % M;
        k += c;
    }

    answer(s);
}

void test_case()
{
    integer n;
    std::cin >> n;

    solve(n);
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
