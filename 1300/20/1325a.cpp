#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void test_case()
{
    unsigned x;
    std::cin >> x;

    answer(1, x - 1);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

