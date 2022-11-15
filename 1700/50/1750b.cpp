#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    integer f[2] = { (s[0] == '0'), (s[0] == '1') }, c = 1, x = 1;
    for (size_t i = 1; i < n; ++i) {
        ++f[s[i]-'0'];
        if (s[i] == s[i-1]) {
            ++c;
            x = std::max(x, c * c);
        } else {
            c = 1;
        }
    }

    answer(std::max(x, f[0] * f[1]));
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
