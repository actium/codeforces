#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(size_t n)
{
    if (n < 3)
        return no_answer();

    if (n == 3)
        return answer("210");

    unsigned x = 100;
    for (size_t i = 3; i < n; ++i)
        x = x * 10 % 210;

    x = (210 - x) % 210;

    std::string s(n, '0');
    s[0] = '1';
    for (auto it = s.rbegin(); x != 0; x /= 10)
        *it++ += x % 10;

    answer(s);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
