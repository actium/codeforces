#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned x)
{
    const auto f = [x](unsigned k) {
        const auto q = k * (k + 1ull) / 2;
        return q >= x && x != q-1;
    };

    unsigned k = 0;
    while (!f(k))
        ++k;

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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

