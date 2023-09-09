#include <iostream>

unsigned any_factor(unsigned x)
{
    for (unsigned i = 3; i * i <= x; i += 2) {
        if (x % i == 0)
            return i;
    }
    return 1 + (x % 2 == 0);
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned l, unsigned r)
{
    if (r < 4)
        return no_answer();

    for (unsigned i = r; i >= l; --i) {
        const unsigned x = any_factor(i);
        if (x != 1)
            return answer(x, i - x);
    }

    no_answer();
}

void test_case()
{
    unsigned l, r;
    std::cin >> l >> r;

    solve(l, r);
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
