#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t x = s.find('>');
    if (x == 0 || x == std::string::npos)
        return answer(0);

    const size_t y = s.rfind('<');
    answer(std::min(x, s.length()-1-y));
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

