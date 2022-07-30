#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x, const unsigned (&a)[3])
{
    unsigned k = 0;
    while (x != 0) {
        ++k;
        x = a[x-1];
    }

    answer(k == 3);
}

void test_case()
{
    unsigned x;
    std::cin >> x;

    unsigned a[3];
    std::cin >> a[0] >> a[1] >> a[2];

    solve(x, a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
