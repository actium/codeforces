#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t h, size_t m)
{
    answer((24 - h) * 60 - m);
}

void test_case()
{
    size_t h, m;
    std::cin >> h >> m;

    solve(h, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

