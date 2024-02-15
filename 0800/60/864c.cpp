#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned a, unsigned b, unsigned f, unsigned k)
{
    unsigned q = 0;
    for (int i = 0, r = b; i < k; ++i) {
        unsigned p = f, s = a - f;
        if (i % 2 == 1)
            std::swap(p, s);

        r -= p;
        if (r < 0)
            return no_answer();

        if (i + 1 == k && r < s || i + 1 < k && r < 2 * s) {
            r = b;
            ++q;
        }

        r -= s;
        if (r < 0)
            return no_answer();
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b, f, k;
    std::cin >> a >> b >> f >> k;

    solve(a, b, f, k);

    return 0;
}
