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

void solve(const std::string& s, size_t x)
{
    const size_t n = s.length();

    std::string w(n, '1');
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '1')
            continue;

        if (i >= x)
            w[i-x] = '0';

        if (i+x < n)
            w[i+x] = '0';
    }

    std::string t(n, ' ');
    for (size_t i = 0; i < n; ++i) {
        if ((i >= x && w[i-x] == '1') || (i+x < n && w[i+x] == '1'))
            t[i] = '1';
        else
            t[i] = '0';
    }

    if (t != s)
        no_answer();
    else
        answer(w);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    size_t x;
    std::cin >> x;

    solve(s, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

