#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const auto match = [&](size_t i, size_t j) {
        return s[i] == '?' || s[i] == s[j] || s[j] == '?';
    };

    const auto check = [&](size_t p) {
        size_t k = 0;
        for (size_t i = 0; i < p; ++i)
            k += match(i, i + p);

        for (size_t i = p; i + p < n && k != p; ++i) {
            k -= match(i - p, i);
            k += match(i, i + p);
        }

        return k == p;
    };

    size_t p = n / 2;
    while (!check(p))
        --p;

    answer(2 * p);
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
