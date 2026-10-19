#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const auto d1 = (s.find("000") != std::string::npos || s.find("111") != std::string::npos);
    const auto d2 = (s.find("101") != std::string::npos || s.find("010") != std::string::npos);

    answer(1 + d1 + d2);
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
