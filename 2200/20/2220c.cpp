#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned p, unsigned q)
{
    const unsigned k = p + 2 * q;

    for (unsigned n = 1; 2 * n * (n + 1) <= k; ++n) {
        if ((k - n) % (2 * n + 1) != 0)
            continue;

        const unsigned m = (k - n) / (2 * n + 1);
        if (p >= m - n)
            return answer(m, n);
    }

    no_answer();
}

void test_case()
{
    unsigned p, q;
    std::cin >> p >> q;

    solve(p, q);
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
