#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const auto check_prefix = [&](size_t i, size_t j) {
        size_t x = j - i + 1;
        while (x > 0 && s[j] == s[x-1])
            --j, --x;

        return x > 0;
    };

    const auto check_suffix = [&](size_t i, size_t j) {
        size_t x = n - (j - i + 1);
        while (x < n && s[i] == s[x])
            ++i, ++x;

        return x < n;
    };

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i; j < n; ++j)
            k += check_prefix(i, j) ^ check_suffix(i, j);
    }

    answer(k);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
