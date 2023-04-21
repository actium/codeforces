#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    {
        char x = ' ';
        for (size_t i = 0; i < n; ++i) {
            if (s[i] == '_' && x != '^')
                ++k;

            x = s[i];
        }
        k += (x == '_' || n == 1);
    }
    answer(k);
}

void test_case()
{
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
