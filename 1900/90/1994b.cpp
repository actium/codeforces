#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    answer(s.find('1') <= t.find('1'));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
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
