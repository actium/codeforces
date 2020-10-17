#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned x1, unsigned y1, unsigned x2, unsigned y2)
{
    const unsigned dx = abs(x2 - x1);
    const unsigned dy = abs(y2 - y1);

    answer(dx + dy + (dx != 0 && dy != 0 ? 2 : 0));
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

