#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> d(n);
    for (size_t i = 1; i < n; ++i)
        d[i] = d[i-1] + (s[i-1] - '0');

    std::reverse(s.begin(), s.end());
    std::reverse(d.begin(), d.end());

    s.append("00");
    d.push_back(0);
    d.push_back(0);

    for (size_t i = 0; i < n || d[i] != 0; ++i) {
        const unsigned x = (s[i] - '0') + d[i];
        s[i] = '0' + x % 10;
        d[i+1] += x / 10;
    }

    while (s.length() > 1 && s.back() == '0')
        s.pop_back();

    std::reverse(s.begin(), s.end());
    answer(s);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
