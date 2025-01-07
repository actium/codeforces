#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned k, unsigned l1, unsigned r1, unsigned l2, unsigned r2)
{
    using integer = unsigned long long;

    unsigned q = 0;
    for (integer p = 1; p <= r2; p *= k) {
        const unsigned lb = std::max<unsigned>(l1, (l2 + p - 1) / p);
        const unsigned ub = std::min<unsigned>(r1, r2 / p);
        q += (ub >= lb ? ub - lb + 1 : 0);
    }

    answer(q);
}

void test_case()
{
    unsigned k, l1, r1, l2, r2;
    std::cin >> k >> l1 >> r1 >> l2 >> r2;

    solve(k, l1, r1, l2, r2);
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
