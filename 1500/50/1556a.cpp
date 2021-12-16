#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned c, unsigned d)
{
    if (c == 0 && d == 0)
        return answer(0);

    if (c == d)
        return answer(1);

    if ((d - c) % 2 == 0)
        return answer(2);

    no_answer();
}

void test_case()
{
    unsigned c, d;
    std::cin >> c >> d;

    solve(c, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
