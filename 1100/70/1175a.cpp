#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n, integer k)
{
    integer c = 0;
    while (true) {
        const integer r = n % k;
        n -= r, c += r;
        if (n == 0)
            break;

        n /= k, ++c;
    }

    answer(c);
}

void test_case()
{
    integer n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

