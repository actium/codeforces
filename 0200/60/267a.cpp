#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    size_t k = 0;
    while (a != 0 && b != 0) {
        if (a > b) {
            const unsigned c = a / b;
            a -= c * b, k += c;
        } else {
            const unsigned c = b / a;
            b -= c * a, k += c;
        }
    }

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

