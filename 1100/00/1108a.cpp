#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void test_case()
{
    unsigned l1, r1, l2, r2;
    std::cin >> l1 >> r1 >> l2 >> r2;

    if (l1 != l2)
        return answer(l1, l2);

    if (r1 != r2) 
        return answer(r1, r2);

    answer(l1, r2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

