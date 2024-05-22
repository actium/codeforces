#include <iostream>

unsigned f[46] = { 1, 1 };

void initialize()
{
    for (size_t i = 2; i < 46; ++i)
        f[i] = f[i-2] + f[i-1];
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool check(unsigned n, unsigned r, unsigned c)
{
    if (n == 1)
        return true;

    if (c > f[n])
        return check(n-1, c - f[n], r);

    if (c + f[n] <= f[n+1])
        return check(n-1, c, r);

    return false;
}

void solve(unsigned n, unsigned x, unsigned y)
{
    answer(check(n, x, y));
}

void test_case()
{
    unsigned n, x, y;
    std::cin >> n >> x >> y;

    solve(n, x, y);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
