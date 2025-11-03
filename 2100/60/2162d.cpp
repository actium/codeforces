#include <iostream>

unsigned query(unsigned t, unsigned l, unsigned r)
{
    std::cout << t << ' ' << l << ' ' << r << std::endl;

    unsigned x;
    std::cin >> x;
    return x;
}

void answer(unsigned l, unsigned r)
{
    std::cout << '!' << ' ' << l << ' ' << r << std::endl;
}

void solve(unsigned n)
{
    unsigned lb = 0, ub = n;
    while (ub - lb > 1) {
        const unsigned mid = (lb + ub) / 2;
        (query(1, 1, mid) == query(2, 1, mid) ? lb : ub) = mid;
    }

    const unsigned l = ub, r = ub + query(2, 1, n) - query(1, 1, n) - 1;

    answer(l, r);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
