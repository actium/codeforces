#include <iostream>
#include <numeric>

using integer = unsigned long long;

void answer(bool v)
{
    constexpr const char* s[2] = { "Infinite", "Finite" };
    std::cout << s[v] << '\n';
}

void solve(integer p, integer q, integer b)
{
    q /= std::gcd(p, q);

    for (b = std::gcd(b, q); b != 1; b = std::gcd(b, q)) {
        while (q % b == 0)
            q /= b;
    }

    answer(q == 1);
}

void test_case()
{
    integer p, q, b;
    std::cin >> p >> q >> b;

    solve(p, q, b);
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
