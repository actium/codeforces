#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    unsigned p = 1;
    while (true) {
        const unsigned q = (n + p) / (2 * p);
        if (k <= q)
            break;

        k -= q;
        p *= 2;
    }

    answer(k * p * 2 - p);
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

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
