#include <iostream>
#include <map>
#include <string>

void answer(const std::pair<size_t, size_t>& x)
{
    std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::pair<size_t, size_t> a = { 0, n + 1 };

    std::map<std::pair<int, int>, size_t> r;
    std::pair<int, int> p = { 0, 0 };
    r[p] = 0;
    for (size_t i = 0; i < n; ++i) {
        switch (s[i]) {
            case 'L': --p.first; break;
            case 'R': ++p.first; break;
            case 'U': ++p.second; break;
            case 'D': --p.second; break;
        }

        const auto it = r.find(p);
        if (it != r.end() && i - it->second < a.second - a.first) {
            a.first = it->second;
            a.second = i;
        }

        r[p] = 1 + i;
    }

    if (a.second - a.first > n)
        return no_answer();

    answer(a);
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
