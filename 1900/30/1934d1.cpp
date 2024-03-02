#include <iostream>

using integer = unsigned long long;

const unsigned w = __builtin_clzll(1);

void answer(integer x, integer y)
{
    std::cout << 1 << '\n';
    std::cout << x << ' ' << y << '\n';
}

void answer(integer x, integer y, integer z)
{
    std::cout << 2 << '\n';
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(integer n, integer m)
{
    if ((n ^ m) < n)
        return answer(n, m);

    const unsigned u = w - __builtin_clzll(n), v = w - __builtin_clzll(m);
    for (unsigned i = v + 1; i < u; ++i) {
        if ((n & 1ll << i) != 0)
            return answer(n, (2ll << i) - 1, m);
    }

    no_answer();
}

void test_case()
{
    integer n, m;
    std::cin >> n >> m;

    solve(n, m);
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
