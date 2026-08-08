#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 1;
    for (size_t i = 1; i < n; ++i) {
        if (s[i] != s[i-1])
            ++k;
    }

    unsigned d = 0;
    for (size_t i = 1; i + 1 < n; ++i) {
        if (s[i-1] == s[i] || s[i] == s[i+1])
            continue;

        if (s[i-1] == s[i+1])
            return answer(k - 2);

        d = 1;
    }

    answer(k - d);
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
