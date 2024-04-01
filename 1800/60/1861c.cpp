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
        switch (c) {
            case '-':
                t.pop_back();
                break;

            case '+':
                if (t.empty())
                    t.push_back('1');
                else
                    t.push_back(t.back() == '0' ? '0' : '2');
                break;

            case '1':
                if (!t.empty() && t.back() == '0')
                    return answer(false);

                for (auto it = t.rbegin(); it != t.rend() && *it == '2'; *it++ = '1');
                break;

            case '0':
                if (t.empty() || t.back() == '1')
                    return answer(false);

                t.back() = '0';
                break;
        }
    }

    answer(true);
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
