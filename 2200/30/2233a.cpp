#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned x, unsigned y, unsigned z)
{
    const unsigned t1 = (n - 1) / (x + y) + 1;
    const unsigned t2 = z + (n - z * x - 1) / (x + 10 * y) + 1;

    answer(z * x >= n ? t1 : std::min(t1, t2));
}

void test_case()
{
    unsigned n, x, y, z;
    std::cin >> n >> x >> y >> z;

    solve(n, x, y, z);
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
