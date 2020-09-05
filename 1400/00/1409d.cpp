#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n, unsigned s)
{
    unsigned sum = 0;
    for (integer x = n; x != 0; x /= 10)
        sum += x % 10;

    integer k = 0;
    for (integer b = 1, c = 0; sum > s; n /= 10, b *= 10) {
        const unsigned d = n % 10 + c;
        c = 0;

        if (d != 0) {
            k += (10 - d) * b;
            sum -= d - 1;
            c = 1;
        }
    }

    answer(k);
}

void test_case()
{
    integer n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    solve(n, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

