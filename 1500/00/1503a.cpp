#include <iostream>
#include <string>

void answer(const std::string& x, const std::string& y)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    if (s[0] == '0' || s[n-1] == '0')
        return no_answer();

    unsigned f[2] = {};
    for (const char c : s)
        ++f[c-'0'];

    if (f[0] % 2 == 1 || f[1] % 2 == 1)
        return no_answer();

    std::string a, b;
    for (size_t i = 0, k = 0, t = 0; i < n; ++i) {
        if (s[i] == '1') {
            a.push_back(k < f[1] ? '(' : ')');
            b.push_back(k < f[1] ? '(' : ')');
            k += 2;
        } else {
            a.push_back(t == 0 ? '(' : ')');
            b.push_back(t == 1 ? '(' : ')');
            t ^= 1;
        }
    }

    answer(a, b);
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
