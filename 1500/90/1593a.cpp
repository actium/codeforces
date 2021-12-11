#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    const auto count = [](unsigned x, unsigned a, unsigned b) {
        const auto k = std::max(a, b);

        return k >= x ? k - x + 1 : 0;
    };

    answer(count(a, b, c), count(b, a, c), count(c, a, b));
}

void test_case()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
