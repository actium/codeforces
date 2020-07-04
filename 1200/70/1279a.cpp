#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(size_t r, size_t g, size_t b)
{
    size_t min1 = r, min2 = g, max = b;
    if (min1 > max)
        std::swap(min1, max);
    if (min2 > max)
        std::swap(min2, max);

    answer(min1 + min2 + 1 >= max);
}

void test_case()
{
    size_t r, g, b;
    std::cin >> r >> g >> b;

    solve(r, g, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

