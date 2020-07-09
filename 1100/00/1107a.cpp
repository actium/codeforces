#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    if (n == 2 && s.front() >= s.back()) {
        answer(false);
    } else {
        answer(true);

        std::cout << 2 << '\n';
        std::cout << s.front() << ' ' << s.substr(1) << '\n';
    }
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

