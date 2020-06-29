#include <iostream>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(unsigned x1, unsigned y1, unsigned x2, unsigned y2)
{
    if (x1 > x2 || y1 > y2)
        return answer(0);

    answer(1ull * (x2 - x1) * (y2 - y1) + 1);
}

void test_case()
{
    unsigned x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    solve(x1, y1, x2, y2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

