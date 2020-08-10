#include <iostream>

#include <cmath>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool test(unsigned n, unsigned d, unsigned x)
{
    return x + (d + x) / (x + 1) <= n;
}

void solve(unsigned n, unsigned d)
{
    const unsigned x = sqrt(d);

    answer(test(n, d, x - 1) || test(n, d, x + 1));
}

void test_case()
{
    unsigned n, d;
    std::cin >> n >> d;

    solve(n, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

