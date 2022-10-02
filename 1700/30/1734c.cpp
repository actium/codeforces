#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& t)
{
    const size_t n = t.length();

    integer c = 0;

    std::string s(n, '1');
    for (unsigned i = 1; i <= n; ++i) {
        for (size_t j = i - 1; j < n && t[j] == '0'; j += i) {
            if (s[j] == '1') {
                s[j] = '0';
                c += i;
            }
        }
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string t;
    std::cin >> t;

    solve(t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
