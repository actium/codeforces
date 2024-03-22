#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::string t;
    for (size_t i = 0, x = -1; i < n; ++i) {
        const size_t p = t.find(s[i]);
        if (p != std::string::npos && x < p && x + 1 == p) {
            ++x;
            continue;
        }
        if (p != std::string::npos && p < x && p + 1 == x) {
            --x;
            continue;
        }
        if (p == std::string::npos && x == 0) {
            t.insert(t.begin(), s[i]);
            continue;
        }
        if (p == std::string::npos && ++x == t.length()) {
            t.insert(t.end(), s[i]);
            continue;
        }
        return no_answer();
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        if (t.find(c) == std::string::npos)
            t.push_back(c);
    }

    answer(t);
}

void test_case()
{
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
