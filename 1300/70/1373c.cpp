#include <iostream>
#include <string>

using integer = long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    integer res = 0, m = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '-')
            --m;
        else
            ++m;

        if (m < 0) {
            res += i + 1;
            m = 0;
        }
    }

    answer(res + n);
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

