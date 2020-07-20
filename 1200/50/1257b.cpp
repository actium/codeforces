#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x, unsigned y)
{
    if (x == 1)
        return answer(y == 1);

    answer(x > 3 || y < 4);
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

