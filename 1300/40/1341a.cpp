#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, size_t a, size_t b, size_t c, size_t d)
{
    const size_t min_x = a - b;
    const size_t max_x = a + b;

    const size_t min_y = c - d;
    const size_t max_y = c + d;

    answer(max_x * n >= min_y && min_x * n <= max_y);
}

void test_case()
{
    size_t n, a, b, c, d;
    std::cin >> n >> a >> b >> c >> d;

    solve(n, a, b, c, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}


