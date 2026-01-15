#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned s, unsigned k, unsigned m)
{
    if (k < s && m / k % 2 == 1)
        s = k;

    m %= k;

    answer(s > m ? s - m : 0);
}

void test_case()
{
    unsigned s, k, m;
    std::cin >> s >> k >> m;

    solve(s, k, m);
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
