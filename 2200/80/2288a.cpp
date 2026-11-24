#include <iostream>

constexpr unsigned oo = ~0u >> 1;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned count(unsigned p, unsigned x)
{
    unsigned k = 0;
    while (p != 0 && x != 0) {
        x -= std::min(x, p--);
        ++k;
    }
    return x == 0 ? k : oo;
}

void solve(unsigned x)
{
    unsigned k = oo;
    for (unsigned p = 1; p < 160; ++p)
        k = std::min(k, p - 1 + count(p, x));

    answer(k);
}

void test_case()
{
    unsigned x;
    std::cin >> x;

    solve(x);
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
