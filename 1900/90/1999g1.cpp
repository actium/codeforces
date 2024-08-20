#include <iostream>

bool check(unsigned x)
{
    std::cout << '?' << ' ' << x << ' ' << x << std::endl;

    unsigned s;
    std::cin >> s;
    return s == x * x;
}

void answer(unsigned x)
{
    std::cout << '!' << ' ' << x << std::endl;
}

void solve()
{
    unsigned lb = 1, ub = 999;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
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
