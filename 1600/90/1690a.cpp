#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned n)
{
    switch (n % 3) {
        case 0:
            return answer(n / 3, n / 3 + 1, n / 3 - 1);
        case 1:
            return answer(n / 3, n / 3 + 2, n / 3 - 1);
        case 2:
            return answer(n / 3 + 1, n / 3 + 2, n / 3 - 1);
    }
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
