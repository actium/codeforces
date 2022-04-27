#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 1;
    for (size_t i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            ++k;
        } else if (k > 1) {
            k = 1;
        } else {
            return answer(false);
        }
    }

    answer(true);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    s.push_back(' ');       // sentinel
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
