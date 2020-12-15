#include <iostream>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned x)
{
    unsigned n = 0;
    for (unsigned d = 9, b = 1; d > 0; --d) {
        if (x >= d) {
            n += d * b;
            b *= 10;
            x -= d;
        }
    }

    if (x != 0)
        return no_answer();

    answer(n);
}

void test_case()
{
    unsigned x;
    std::cin >> x;

    solve(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

