#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, std::string& t)
{
    const size_t n = s.length();

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0')
            continue;

        if (t[i] == '0') {
            t[i] = '2';
            ++k;
            continue;
        }
        if (i > 0 && t[i-1] == '1') {
            t[i-1] = '2';
            ++k;
            continue;
        }
        if (i+1 < n && t[i+1] == '1') {
            t[i+1] = '2';
            ++k;
            continue;
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string t, s;
    std::cin >> t >> s;

    solve(s, t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
