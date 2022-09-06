#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length(), r = n - 1;

    integer t = 0;
    for (size_t i = 0; i < n; ++i)
        t += (s[i] == 'L' ? i : r-i);

    std::vector<integer> v(n);
    for (size_t k = 0, d = 0; k < n; ++k) {
        while (d < r / 2 && s[d] == 'R' && s[r-d] == 'L')
            ++d;

        if (s[d] == 'L') {
            s[d] = 'R';
            t += r - 2 * d;
        } else if (s[r-d] == 'R') {
            s[r-d] = 'L';
            t += r - 2 * d;
        }
        v[k] = t;
    }

    answer(v);
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
