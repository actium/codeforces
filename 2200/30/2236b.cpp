#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string& s, size_t k)
{
    const size_t n = s.size();

    for (size_t i = k; i < n; ++i) {
        if (s[i-k] == '1') {
            s[i-k] ^= 1;
            s[i] ^= 1;
        }
    }

    answer(s.find('1') == std::string::npos);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
