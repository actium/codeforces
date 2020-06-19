#include <iostream>

using integer = unsigned long long;

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(integer n)
{
    size_t count = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n = 1 * n / 2;
        } else if (n % 3 == 0) {
            n = 2 * n / 3;
        } else if (n % 5 == 0) {
            n = 4 * n / 5;
        } else {
            return answer(-1);
        }
        ++count;
    }

    answer(count);
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

