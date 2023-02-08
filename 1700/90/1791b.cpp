#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    int x = 0, y = 0;
    for (const char c : s) {
        switch (c) {
            case 'L': --x; break;
            case 'R': ++x; break;
            case 'D': --y; break;
            case 'U': ++y; break;
        }

        if (x == 1 && y == 1)
            return answer(true);
    }

    answer(false);
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
