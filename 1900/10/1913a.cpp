#include <iostream>
#include <string>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t x = 1;
    while (x < n - 1 && s[x] == '0')
        ++x;

    const unsigned u = std::stoi(s.substr(0, x)), v = std::stoi(s.substr(x));
    u < v ? answer(u, v) : no_answer();
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
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
