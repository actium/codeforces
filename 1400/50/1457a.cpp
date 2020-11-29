#include <algorithm>
#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned m, unsigned r, unsigned c)
{
    --n, --m, --r, --c;
    answer(std::max({ r + c, n-r + c, r + m-c, n-r + m-c }));
}

void test_case()
{
    unsigned n, m, r, c;
    std::cin >> n >> m >> r >> c;

    solve(n, m, r, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

