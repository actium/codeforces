#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string& s, size_t k)
{
    const size_t n = s.length();

    for (size_t i = k; i < n; ++i) {
        if (s[i] == '?')
            s[i] = s[i-k];
    }
    for (size_t i = n-1-k; ~i; --i) {
        if (s[i] == '?')
            s[i] = s[i+k];
    }

    unsigned f[2] = {};
    for (size_t i = 0; i < k; ++i) {
        if (s[i] != '?')
            ++f[s[i] - '0'];
    }

    if (f[0] > k/2 || f[1] > k/2)
        return answer(false);

    for (size_t i = k; i < n; ++i) {
        if (s[i] != s[i-k])
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

