#include <iostream>

unsigned query(unsigned a, unsigned b)
{
    std::cout << '?' << ' ' << a << ' ' << b << std::endl;

    unsigned s;
    std::cin >> s;
    return s;
}

void answer(unsigned x)
{
    std::cout << '!' << ' ' << x << std::endl;
}

void solve()
{
    unsigned lb = 1, ub = 999;
    while (lb + 1 < ub) {
        const unsigned mid1 = (2 * lb + ub) / 3, mid2 = (lb + 2 * ub) / 3, s = query(mid1, mid2);

        if (s == mid1 * mid2)
            lb = mid2;

        if (s == mid1 * (mid2 + 1)) {
            lb = mid1;
            ub = mid2;
        }

        if (s == (mid1 + 1) * (mid2 + 1))
            ub = mid1;
    }

    answer(ub);
}

void test_case()
{
    solve();
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
