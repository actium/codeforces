#include <array>
#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::array<std::string, 2>& s)
{
    const size_t n = s[0].length();

    unsigned k = 0;
    for (size_t i = 2; i < n; ++i) {
        if (s[0][i-2] == 'x' && s[0][i-1] == '.' && s[0][i] == 'x')
            k += (s[1][i-2] == '.' && s[1][i-1] == '.' && s[1][i] == '.');

        if (s[1][i-2] == 'x' && s[1][i-1] == '.' && s[1][i] == 'x')
            k += (s[0][i-2] == '.' && s[0][i-1] == '.' && s[0][i] == '.');
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::array<std::string, 2> s;
    std::cin >> s[0] >> s[1];

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
