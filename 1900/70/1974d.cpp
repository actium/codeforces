#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    if (n == 2 && s[0] != s[1])
        return no_answer();

    int x = 0, y = 0;
    for (const char c : s) {
        switch (c) {
            case 'N': ++y; break;
            case 'E': ++x; break;
            case 'S': --y; break;
            case 'W': --x; break;
        }
    }

    if (x % 2 != 0 || y % 2 != 0)
        return no_answer();

    std::string t(n, 'H');
    for (size_t i = 0; i == 0 || x != 0 || y != 0; ++i) {
        switch (s[i]) {
            case 'N':
                if (i == 0 || y > 0) {
                    t[i] = 'R';
                    y -= 2;
                }
                break;
            case 'E':
                if (i == 0 || x > 0) {
                    t[i] = 'R';
                    x -= 2;
                }
                break;
            case 'S':
                if (i == 0 || y < 0) {
                    t[i] = 'R';
                    y += 2;
                }
                break;
            case 'W':
                if (i == 0 || x < 0) {
                    t[i] = 'R';
                    x += 2;
                }
                break;
        }
    }

    answer(t);
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
