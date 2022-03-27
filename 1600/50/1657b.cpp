#include <iostream>

using integer = long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(size_t n, int b, int x, int y)
{
    integer a = 0, s = 0;
    for (size_t i = 0; i < n; ++i) {
        if (a + x <= b) {
            a += x;
        } else {
            a -= y;
        }
        s += a;
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    int b, x, y;
    std::cin >> b >> x >> y;

    solve(n, b, x, y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

