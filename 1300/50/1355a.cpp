#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer a, integer k)
{
    for (integer z = 0; --k > 0 && a != z; ) {
        z = a;

        unsigned min = 9, max = 0;
        do {
            const unsigned d = a % 10;
            min = std::min(min, d);
            max = std::max(max, d);
            a /= 10;
        } while (a != 0);

        a = z + min * max;
    }

    answer(a);
}

void test_case()
{
    integer a, k;
    std::cin >> a >> k;

    solve(a, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

