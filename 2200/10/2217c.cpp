#include <iostream>
#include <numeric>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << std::endl;
}

void solve(unsigned n, unsigned m, unsigned a, unsigned b)
{
    if (std::gcd(a, n) != 1)
        return answer(false);

    if (std::gcd(b, m) != 1)
        return answer(false);

    answer(std::gcd(n, m) <= 2);
}

void test_case()
{
    unsigned n, m, a, b;
    std::cin >> n >> m >> a >> b;

    solve(n, m, a, b);
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
