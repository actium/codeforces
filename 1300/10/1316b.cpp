#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x, unsigned y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::pair<std::string, unsigned> r = { s, 1 };
    for (size_t i = 1; i < n; ++i) {
        if (s[i] > r.first[0])
            continue;

        std::string u = s.substr(0, i), v = s.substr(i);
        if ((n - i) % 2 == 1)
            std::reverse(u.begin(), u.end());

        v += u;
        if (v < r.first) {
            r.first = std::move(v);
            r.second = 1 + i;
        }
    }

    answer(r.first, r.second);
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
