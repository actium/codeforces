#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned s, unsigned t)
{
    const unsigned k = (s + t) - n;
    n -= k, s -= k, t -= k;

    answer(n - std::min(s, t) + 1);
}

void test_case()
{
    unsigned n, s, t;
    std::cin >> n >> s >> t;

    solve(n, s, t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

