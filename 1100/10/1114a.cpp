#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(size_t x, size_t y, size_t z, size_t a, size_t b, size_t c)
{
    if (a < x)
        return answer(false);

    a -= x;

    if (a + b < y)
        return answer(false);

    answer(a + b + c - y >= z);
}

int main()
{
    size_t x, y, z;
    std::cin >> x >> y >> z;

    size_t a, b, c;
    std::cin >> a >> b >> c;

    solve(x, y, z, a, b, c);

    return 0;
}

