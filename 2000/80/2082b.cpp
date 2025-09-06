#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned x, unsigned n, unsigned m)
{
    const auto relax = [](unsigned v, unsigned d, unsigned k) {
        for (k = std::min(k, 30u); k != 0; --k)
            v = (v + d) / 2;

        return v;
    };

    answer(relax(relax(x, 1, m), 0, n), relax(relax(x, 0, n), 1, m));
}

void test_case()
{
    unsigned x, n, m;
    std::cin >> x >> n >> m;

    solve(x, n, m);
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
