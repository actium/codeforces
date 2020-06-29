#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    const auto p1 = s.find('1');
    if (p1 == std::string::npos)
        return answer(s);

    const auto p2 = s.rfind('0');
    if (p2 == std::string::npos)
        return answer(s);

    if (p1 > p2)
        return answer(s);

    s.erase(p1, p2 - p1 + 1);
    s = '0' + s;
    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

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

