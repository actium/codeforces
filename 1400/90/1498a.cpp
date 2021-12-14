#include <iostream>
#include <numeric>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n)
{
    const auto sum = [](integer x) {
        unsigned s = 0;
        while (x != 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    };

    while (std::gcd(n, sum(n)) == 1)
        ++n;

    answer(n);
}

void test_case()
{
    integer n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
