#include <iostream>

using integer = unsigned long long;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned k, integer x)
{
    const auto test = [=](unsigned q) {
        const integer p = std::min(q, k);

        integer s = p * (p + 1) / 2;
        if (q > k) {
            q -= k;
            s += q * integer(2 * k - q - 1) / 2;
        }
        return s < x;
    };

    unsigned ub = 2 * k - 1;
    for (unsigned lb = 0; lb + 1 < ub; ) {
        const unsigned mid = lb + (ub - lb) / 2;
        if (test(mid))
            lb = mid;
        else
            ub = mid;
    }

    answer(ub);
}

void test_case()
{
    unsigned k;
    std::cin >> k;

    integer x;
    std::cin >> x;

    solve(k, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
