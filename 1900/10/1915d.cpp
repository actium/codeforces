#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::string t;
    for (size_t i = n; i != 0; ) {
        const size_t k = (s[i-1] == 'a' || s[i-1] == 'e' ? 2 : 3);
        for (size_t j = 0; j < k; ++j)
            t.push_back(s[--i]);

        t.push_back('.');
    }
    t.pop_back();

    std::reverse(t.begin(), t.end());

    answer(t);
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
