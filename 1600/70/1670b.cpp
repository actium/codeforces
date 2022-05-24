#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::vector<bool>& v)
{
    const size_t n = s.length();

    size_t p = 0, k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (v[s[i]-'a']) {
            k = std::max(k, i - p);
            p = i;
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    size_t k;
    std::cin >> k;

    std::vector<bool> v(26);
    for (size_t i = 0; i < k; ++i) {
        char c;
        std::cin >> c;

        v[c-'a'] = true;
    }

    solve(s, v);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
