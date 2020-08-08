#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& t)
{
    const size_t n = t.length();

    unsigned z = 0;
    for (const char c : t)
        z += (c == '0');

    if (z == 0 || z == n)
        return answer(t);

    std::string s;
    for (size_t i = 0; i < n; ++i)
        s += "01";

    answer(s);
}

void test_case()
{
    std::string t;
    std::cin >> t;

    solve(t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

