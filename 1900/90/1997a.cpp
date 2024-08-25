#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 1; i < n; ++i) {
        if (s[i-1] == s[i]) {
            s.insert(s.begin() + i, 'a' + (s[i] == 'a'));
            return answer(s);
        }
    }

    s.push_back('a' + (s[n-1] == 'a'));
    answer(s);
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
