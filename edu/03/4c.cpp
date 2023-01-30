#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> z(n), q(1 + n);
    for (size_t i = 1, j = 0; i < n; ++i) {
        unsigned& p = z[i];
        if (j + z[j] > i)
            p = std::min<unsigned>(j + z[j] - i, z[i - j]);

        while (i + p < n && s[p] == s[i + p])
            ++p;

        if (j + z[j] < i + p)
            j = i;

        ++q[p+1];
    }

    std::vector<unsigned> f(n);
    for (size_t i = 1; i <= n; ++i) {
        q[i] += q[i-1];
        f[i-1] = n - q[i];
    }

    answer(f);
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
