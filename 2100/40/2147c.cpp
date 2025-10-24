#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool check(const std::string& s)
{
    if (s.empty() || s.front() == '0' || s.back() == '0')
        return true;

    unsigned k = 0;
    for (const char c : s)
        k += (c == '0');

    return k % 2 == 0;
}

void solve(const std::string& s)
{
    std::string t;
    for (const char c : s) {
        if (!t.empty() && c == t.back()) {
            if (!check(t))
                return answer(false);

            t.clear();
        }
        t.push_back(c);
    }

    answer(check(t));
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
