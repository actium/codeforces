#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned w, unsigned h, unsigned n)
{
    answer((1 << __builtin_ctz(w)) * (1 << __builtin_ctz(h)) >= n);
}

void test_case()
{
    unsigned w, h, n;
    std::cin >> w >> h >> n;

    solve(w, h, n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

