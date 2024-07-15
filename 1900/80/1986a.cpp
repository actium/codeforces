#include <algorithm>
#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x1, unsigned x2, unsigned x3)
{
    answer(std::max({ x1, x2, x3 }) - std::min({ x1, x2, x3 }));
}

void test_case()
{
    unsigned x1, x2, x3;
    std::cin >> x1 >> x2 >> x3;

    solve(x1, x2, x3);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
