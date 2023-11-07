#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

std::vector<unsigned> z(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> z(n);
    for (size_t i = 1, j = 0; i < n; ++i) {
        if (i < j + z[j])
            z[i] = std::min<unsigned>(j + z[j] - i, z[i-j]);

        while (i + z[i] < 2 * n && s[i + z[i]] == s[z[i]])
            ++z[i];

        if (j + z[j] < i + z[i])
            j = i;
    }
    return z;
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const std::string t(s.rbegin(), s.rend());

    size_t k = 0;
    while (k < n / 2 && s[k] == t[k])
        ++k;

    const auto f = [&](const std::string& s, unsigned b) {
        const size_t n = s.length();

        const std::vector<unsigned> t = z(s + std::string(s.rbegin(), s.rend()));

        unsigned k = 0;
        for (size_t i = n; i < 2 * n; ++i) {
            if (t[i] == 2 * n - i && t[i] <= b)
                k = std::max(k, t[i]);
        }
        return k;
    };

    const unsigned p = f(s.substr(k), n - 2 * k), q = f(t.substr(k), n - 2 * k);
    if (p > q) {
        answer(s.substr(0, k + p) + s.substr(n - k));
    } else {
        answer(s.substr(0, k) + s.substr(n - k - q));
    }
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
