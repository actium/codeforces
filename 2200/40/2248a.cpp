#include <iostream>
#include <string>

void answer(const std::string& s)
{
    std::cout << s << '\n';
}

void solve(std::string& s)
{
    s.erase(s.find('0'), 1);
    s.erase(s.find('1'), 1);

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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
