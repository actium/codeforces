#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned r, unsigned b, unsigned d)
{
    if (r > b)
        std::swap(r, b);

    answer(b - r <= 1ull * r * d);
}

void test_case()
{
    unsigned r, b, d;
    std::cin >> r >> b >> d;

    solve(r, b, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
