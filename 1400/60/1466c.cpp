#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;

    if (n > 1 && s[1] == s[0]) {
        s[1] = '*';
        ++k;
    }

    for (size_t i = 2; i < n; ++i) {
        if (s[i] == s[i-1] || s[i] == s[i-2]) {
            s[i] = '*';
            ++k;
        }
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

