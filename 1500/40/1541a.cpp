#include <iostream>

void solve(unsigned n)
{
    unsigned x = 1;

    if (n % 2 == 1) {
        std::cout << "3 1 2 ";
        x = 4;
    }

    while (x <= n) {
        std::cout << x + 1 << ' ' << x << ' ';
        x += 2;
    }

    std::cout << '\n';
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

