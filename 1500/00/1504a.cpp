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

bool is_palindrome(const std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 0; i < n / 2; ++i) {
        if (s[i] != s[n-1-i])
            return false;
    }

    return true;
}

void solve(const std::string& s)
{
    const std::string c1 = 'a' + s;
    if (!is_palindrome(c1))
        return answer(c1);

    const std::string c2 = s + 'a';
    if (!is_palindrome(c2))
        return answer(c2);

    no_answer();
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
