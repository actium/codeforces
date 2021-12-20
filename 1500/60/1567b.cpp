#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    unsigned x = 0;
    switch (a % 4) {
        case 1:
            x = a - 1;
            break;
        case 2:
            x = 1;
            break;
        case 3:
            x = a;
            break;
    }

    if (x != b)
        a += 1 + ((x ^ b) == a);

    answer(a);
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
