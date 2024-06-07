#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    std::vector<size_t> p(1, 1);
    for (size_t i = 1; i < n; ++i) {
        if (s[i] != s[i-1])
            p.emplace_back(0);

        ++p.back();
    }

    size_t x = 0;
    for (const size_t q : p) {
        x += q;

        if (q != k) {
            if (q > k)
                x -= k;

            break;
        }
    }

    std::string t = s.substr(0, x);
    std::reverse(t.begin(), t.end());
    t = s.substr(x, n - x) + t;

    for (size_t i = 1; i < k; ++i) {
        if (t[i] != t[0])
            return no_answer();
    }
    for (size_t i = k; i < n; ++i) {
        if (t[i] == t[i-k])
            return no_answer();
    }

    answer(x);
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
