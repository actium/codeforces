#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned x)
{
    const unsigned y = (1 << __builtin_clz(1) - __builtin_clz(x)) - 1, z = x ^ y;

    if (x + y > z && y + z > x && z + x > y)
        return answer(y);

    no_answer();
}

void test_case()
{
    unsigned x;
    std::cin >> x;

    solve(x);
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
