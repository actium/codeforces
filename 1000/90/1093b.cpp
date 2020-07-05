#include <algorithm>
#include <iostream>
#include <string>

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    std::sort(s.begin(), s.end());

    if (s.front() == s.back())
        answer(-1);
    else
        answer(s);
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

