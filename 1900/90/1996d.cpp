#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned x)
{
    integer k = 0;
    for (unsigned a = 1; a + 1 < x && 3 * a * a <= n; ++a) {
        for (unsigned b = a; a + b < x && b * b < n; ++b) {
            const unsigned c = std::min((n - a * b) / (a + b), x - (a + b));
            if (c < b)
                break;

            if (a == b)
                k += 1 + 3 * (c - a);
            else
                k += 3 + 6 * (c - b);
        }
    }

    answer(k);
}

void test_case()
{
    unsigned n, x;
    std::cin >> n >> x;

    solve(n, x);
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
