#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    for (const unsigned x : v)
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

bool check(const std::string& s)
{
    int b = 0;
    for (const char c : s)
        b += (c == '(' ? 1 : -1);

    return b <= 0;
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t x = s.rfind('#');
    while (x < n && s[x] != '(')
        ++x;

    if (x < n && !check(s.substr(x)))
        return no_answer();

    std::vector<unsigned> r;

    int b = 0;
    for (const char c : s) {
        switch (c) {
            case '(':
                ++b;
                break;
            case ')':
                if (--b < 0)
                    return no_answer();
                break;
            case '#':
                r.push_back(1);
                if (--b < 0)
                    return no_answer();
                break;
        }
    }

    r.back() += b;
    answer(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
