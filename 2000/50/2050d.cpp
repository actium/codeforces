#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    for (size_t i = n-1; i > 0; --i) {
        for (size_t j = i; j < n && s[j-1] + 1 < s[j]; ++j)
            std::swap(s[j-1], --s[j]);
    }

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
