#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    size_t k = 0;
    while (n % 3 == 0) {
        if (n % 6 == 0) {
            n /= 6;
            ++k;
        } else {
            n /= 3;
            k += 2;
        }
    }

    if (n == 1)
        answer(k);
    else
        answer(-1);
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

