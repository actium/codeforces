#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a1, unsigned b1, unsigned a2, unsigned b2)
{
    if (a1 > b1)
        std::swap(a1, b1);

    if (a2 > b2)
        std::swap(a2, b2);

    answer(b1 == b2 && a1 + a2 == b1);
}

void test_case()
{
    unsigned a1, b1;
    std::cin >> a1 >> b1;

    unsigned a2, b2;
    std::cin >> a2 >> b2;

    solve(a1, b1, a2, b2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

