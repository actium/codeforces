#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string& s, std::string& t)
{
    while (!s.empty() && !t.empty()) {
        if (s.back() == t.back()) {
            s.pop_back();
            t.pop_back();
        } else {
            s.pop_back();
            if (!s.empty())
                s.pop_back();
        }
    }

    answer(t.empty());
}

void test_case()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
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
