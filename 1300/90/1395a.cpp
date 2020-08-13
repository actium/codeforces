#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(unsigned r, unsigned g, unsigned b, unsigned w)
{
    const unsigned k = r % 2 + g % 2 + b % 2 + w % 2;
    answer(k < 2 || (r > 0 && g > 0 && b > 0 && k > 2));
}

void test_case()
{
    unsigned r, g, b, w;
    std::cin >> r >> g >> b >> w;

    solve(r, g, b, w);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

