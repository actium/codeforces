#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "Ashish", "Utkarsh" };
    std::cout << s[v] << '\n';
}

void solve(unsigned d, unsigned k)
{
    using integer = unsigned long long;

    unsigned x = 0;
    for (integer p = 0, q = 0; p <= d && p * p + q * q <= 1ull * d * d; (q < p ? q : p) += k)
        x = (p + q) / k;

    answer(x % 2 == 0);
}

void test_case()
{
    unsigned d, k;
    std::cin >> d >> k;

    solve(d, k);
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
