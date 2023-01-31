#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& s, size_t k)
{
    for (size_t i = 0; i < k; ++i)
        std::cout << s[i];

    std::cout << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> z(n);
    for (size_t i = 1, j = 0; i < n; ++i) {
        unsigned& p = z[i];
        if (j + z[j] > i)
            p = std::min<unsigned>(j + z[j] - i, z[i - j]);

        while (i + p < n && s[p] == s[i + p])
            ++p;

        if (j + z[j] < i + p)
            j = i;
    }

    size_t k = 1;
    while (k < n && z[k] != n - k)
        ++k;

    answer(s, k);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
