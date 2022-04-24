#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    unsigned f[2] = {};
    for (const char c : s) {
        if (c != 'W') {
            ++f[c == 'R'];
            continue;
        }

        if (f[0] + f[1] == 0)
            continue;

        if (f[0] == 0 || f[1] == 0)
            return answer(false);

        f[0] = f[1] = 0;
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    s.push_back('W');       // sentinel
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
