#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(int x, size_t n, size_t m)
{
    while (x > 20 && n > 0) {
        x = x / 2 + 10;
        --n;
    }
    while (x > 0 && m > 0) {
        x -= 10;
        --m;
    }

    answer(x <= 0);
}

void test_case()
{
    size_t x, n, m;
    std::cin >> x >> n >> m;

    solve(x, n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}


