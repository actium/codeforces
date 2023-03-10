#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n)
{
    const auto allocate = [&](unsigned k) {
        const auto c = std::min(n, k);
        n -= c;
        return c;
    };

    unsigned a = 0, b = 0;
    for (unsigned d = 1; n != 0; d += 8) {
        a += allocate(d);
        b += allocate(d + 4);
    }

    answer(a, b);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
