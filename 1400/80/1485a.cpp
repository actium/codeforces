#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    const auto next = [=](unsigned x) {
        unsigned c = x - b;
        if (x == 1)
            ++x, ++c;

        for (unsigned y = a; y != 0; y /= x)
            ++c;

        return c;
    };

    unsigned k = a + 1;
    for (unsigned c = next(b); c <= k; c = next(++b))
        k = std::min(k, c);

    answer(k);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

