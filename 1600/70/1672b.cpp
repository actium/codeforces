#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    std::string t;
    for (const char c : s) {
        if (c == 'A') {
            t.push_back(c);
            continue;
        }
        if (!t.empty()) {
            t.pop_back();
            continue;
        }
        return answer(false);
    }

    answer(s.back() == 'B');
}

void test_case()
{
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

