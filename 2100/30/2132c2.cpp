#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

unsigned t[19];

void initialize()
{
    t[0] = 3;
    for (size_t i = 1, x = 1; i < 19; ++i, x *= 3)
        t[i] = 3 * t[i-1] + x;
}

void solve(unsigned n, unsigned k)
{
    unsigned q[19] = {};
    for (size_t i = 0; n != 0; n /= 3) {
        if (n % 3 > k)
            return no_answer();

        q[i++] = n % 3;
        k -= n % 3;
    }

    for (size_t i = 18; i > 0; --i) {
        const unsigned m = std::min(q[i], k / 2);
        q[i] -= m;
        q[i-1] += 3 * m;
        k -= 2 * m;
    }

    integer c = 0;
    for (size_t i = 0; i < 19; ++i)
        c += 1ull * q[i] * t[i];

    answer(c);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
