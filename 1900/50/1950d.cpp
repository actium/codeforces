#include <iostream>

constexpr unsigned t[] = {
                     10,    11,   100,   101,   110,   111,
     1000,  1001,  1010,  1011,  1100,  1101,  1110,  1111,
    10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111,
    11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111,
};

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool check(unsigned n)
{
    if (n == 1)
        return true;

    for (const unsigned x : t) {
        if (n % x == 0 && check(n / x))
            return true;
    }
    return false;
}

void solve(unsigned n)
{
    answer(check(n));
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
