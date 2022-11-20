#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 1; i < n; ++i) {
        switch (s[i]) {
            case 'Y':
                if (s[i-1] != 's')
                    return answer(false);
                break;
            case 'e':
                if (s[i-1] != 'Y')
                    return answer(false);
                break;
            case 's':
                if (s[i-1] != 'e')
                    return answer(false);
                break;
            default:
                return answer(false);
        }
    }

    answer(s[0] == 'Y' || s[0] == 'e' || s[0] == 's');
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
