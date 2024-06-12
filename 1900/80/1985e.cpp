#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

std::vector<integer> divisors(integer n)
{
    std::vector<integer> v;
    for (integer x = 1; x * x <= n; ++x) {
        if (n % x == 0) {
            v.push_back(x);
            v.push_back(n / x);
        }
    }
    return v;
}

void solve(unsigned x, unsigned y, unsigned z, integer k)
{
    integer q = 0;
    for (const integer a : divisors(k)) {
        if (a > x)
            continue;

        for (const integer b : divisors(k / a)) {
            if (b > y)
                continue;

            const integer c = k / (a * b);
            if (c > z)
                continue;

            q = std::max(q, (x - a + 1) * (y - b + 1) * (z - c + 1));
        }
    }

    answer(q);
}

void test_case()
{
    unsigned x, y, z;
    std::cin >> x >> y >> z;

    integer k;
    std::cin >> k;

    solve(x, y, z, k);
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
