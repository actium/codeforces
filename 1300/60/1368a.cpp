#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b, unsigned n)
{
    size_t count = 0;
    while (a <= n && b <= n) {
        if (a < b)
            a += b;
        else
            b += a;

        ++count;
    }

    answer(count);
}

void test_case()
{
    unsigned a, b, n;
    std::cin >> a >> b >> n;

    solve(a, b, n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

