#include <iostream>

using integer = long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer a, integer b)
{
    if (a > b)
        return solve(b, a);

    if (a == b)
        return answer(0);

    size_t count = 0;
    while (a < b) {
        a <<= 1;
        ++count;
    }

    if (a == b) {
        const size_t k1 = count / 3;
        count -= k1 * 3;

        const size_t k2 = count / 2;
        count -= k2 * 2;

        return answer(k1 + k2 + count);
    }

    answer(-1);
}

void test_case()
{
    integer a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

