#include <iostream>
#include <numeric>

void answer(bool v)
{
    constexpr const char* s[2] = { "REBEL", "OBEY" };
    std::cout << s[v] << '\n';
}

void solve(unsigned r, unsigned b, unsigned k)
{
    if (r > b)
        std::swap(r, b);

    const unsigned d = std::gcd(r, b);
    r /= d;
    b /= d;

    answer((r + b - 2) / r < k);
}

void test_case()
{
    unsigned r, b, k;
    std::cin >> r >> b >> k;

    solve(r, b, k);
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
