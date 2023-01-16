#include <iostream>
#include <string>

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t x = s.find('R');
    if (x == std::string::npos)
        return answer(-1);

    const size_t y = s.rfind('L');
    if (y == std::string::npos)
        return answer(-1);

    answer(x > y ? x : 0);
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
