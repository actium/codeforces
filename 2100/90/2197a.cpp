#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned sum_digits(unsigned x)
{
    unsigned s = 0;
    while (x != 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

void solve(unsigned x)
{
    for (unsigned d = 1; d < 80; ++d) {
        if (sum_digits(x + d) == d)
            return answer(10);
    }

    answer(0);
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
