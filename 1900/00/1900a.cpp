#include <algorithm>
#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    if (s.find("...") != std::string::npos)
        return answer(2);

    answer(std::count(s.begin(), s.end(), '.'));
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
