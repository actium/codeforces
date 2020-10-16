#include <iostream>

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(unsigned k, unsigned x, unsigned r)
{
    std::cout << "YES" << '\n';

    while (k-- > 0)
        std::cout << x << ' ';

    std::cout << r << '\n';
}

void solve(unsigned n, unsigned k)
{
    if (n >= k) {
        const unsigned r = n - k + 1;
        if (r % 2 == 1)
            return answer(k - 1, 1, r);
    }

    if (n >= 2 * k) {
        const unsigned r = n - 2 * k + 2;
        if (r % 2 == 0)
            return answer(k - 1, 2, r);
    }

    no_answer();
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

