#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();
    if (2 * k + 1 > n)
        return answer(false);

    for (size_t i = 0; i < k; ++i) {
        if (s[i] != s[n-1-i])
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
