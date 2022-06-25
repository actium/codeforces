#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::string t(n, '0');
    for (size_t i = 0; i < n; ++i) {
        t[i] += '9' - s[i];
    }

    if (t[0] == '0') {
        unsigned c = 1;
        for (size_t i = n-1; ~i; --i) {
            t[i] += 1 + c;
            c = (t[i] > '9');
            t[i] -= c * 10;
        }
    }

    answer(t);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
