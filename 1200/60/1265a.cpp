#include <iostream>
#include <string>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '?') {
            const unsigned u = (i > 0 ? s[i-1] : 'a') - 'a';
            const unsigned v = (i < n-1 && s[i+1] != '?' ? s[i+1] : 'a') - 'a';

            if (u == v)
                s[i] = 'a' + (u + 1) % 3;
            else
                s[i] = 'a' + 3 - (u + v);
        }

        if (i > 0 && s[i] == s[i-1])
            return no_answer();
    }

    answer(s);
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

