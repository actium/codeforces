#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n)
{
    const auto f = [](integer n) {
        for (integer x = n; x != 0; x /= 10) {
            const unsigned d = x % 10;
            if (d != 0 && n % d != 0)
                return false;
        }
        return true;
    };

    while (!f(n))
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

