#include <iostream>
#include <string>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::string& s)
{
    const auto count = [&](char x) {
        const size_t n = s.length();

        for (size_t i = 1; i + 1 < n; ++i) {
            if (s[i-1] == '1' && s[i+1] == '1')
                s[i] = x;
        }

        unsigned k = 0;
        for (const char c : s)
            k += c - '0';

        return k;
    };

    const unsigned y = count('1'), x = count('0');
    answer(x, y);
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
