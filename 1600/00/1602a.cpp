#include <algorithm>
#include <iostream>
#include <string>

void answer(const char x, const std::string& y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::string& s)
{
    const auto x = std::min_element(s.cbegin(), s.cend());
    const auto d = std::distance(s.cbegin(), x);

    answer(*x, s.substr(0, d) + s.substr(d + 1));
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

