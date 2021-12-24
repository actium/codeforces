#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    const auto g = [](unsigned x, unsigned f, unsigned k) {
        unsigned lb = 1;
        while (--k > 0)
            lb *= 10;

        while (x < lb)
            x *= f;

        return x;
    };

    const unsigned z = g(1, 3, c);
    answer(g(z, 5, a), g(z, 7, b));
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
