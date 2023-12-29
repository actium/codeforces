#include <array>
#include <iostream>
#include <string>

void answer(char x)
{
    std::cout << x << '\n';
}

void solve(const std::array<std::string, 3>& s)
{
    unsigned f[3] = {};
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            if (isalpha(s[i][j]))
                ++f[s[i][j] - 'A'];
        }
    }

    for (size_t i = 0; i < 3; ++i) {
        if (f[i] == 2)
            return answer('A' + i);
    }
}

void test_case()
{
    std::array<std::string, 3> s;
    for (size_t i = 0; i < 3; ++i)
        std::cin >> s[i];

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
