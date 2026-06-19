#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b, unsigned x)
{
    unsigned c = 0, k = ~0u;
    while (a != b) {
        if (a > b)
            std::swap(a, b);

        k = std::min(k, b - a + c);

        b /= x;
        ++c;
    }

    answer(std::min(c, k));
}

void test_case()
{
    unsigned a, b, x;
    std::cin >> a >> b >> x;

    solve(a, b, x);
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
