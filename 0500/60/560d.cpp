#include <iostream>
#include <string>

#include <cstring>

bool equal(const char* a, const char* b, size_t n) noexcept
{
    if ((n & 1) != 0)
        return memcmp(a, b, n) == 0;

    n >>= 1;
    return equal(a, b, n) && equal(a + n, b + n, n) || equal(a, b + n, n) && equal(a + n, b, n);
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    answer(equal(a.data(), b.data(), a.length()));
}

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

