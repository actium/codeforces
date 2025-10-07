#include <algorithm>
#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i + 1;

    for (size_t i = 0, j = 1; i < n; i = j++) {
        if (s[i] == '0') {
            while (j < n && s[j] == '0')
                ++j;

            std::rotate(p.begin() + i, p.begin() + i + 1, p.begin() + j);
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0' && p[i] == i+1)
            return no_answer();
    }

    answer(p);
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
