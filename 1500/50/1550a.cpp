#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned s)
{
    unsigned k = 1;
    for (unsigned d = 1; d < s; s -= d, d += 2)
        ++k;

    answer(k);
}

void test_case()
{
    unsigned s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

