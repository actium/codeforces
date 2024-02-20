#include <algorithm>
#include <iostream>
#include <string>

void answer(char x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    answer(std::count(s.begin(), s.end(), 'A') > 2 ? 'A' : 'B');
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
