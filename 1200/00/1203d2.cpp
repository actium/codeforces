#include <iostream>
#include <string>
#include <vector>

void answer(size_t x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length(), m = t.length();

    std::vector<unsigned> ps(1 + n);
    for (size_t i = 0, k = 0; i < n; ++i) {
        if (k < m && s[i] == t[k])
            ++k;

        ps[i+1] = k;
    }

    std::vector<unsigned> ss(n + 1);
    for (size_t i = n, k = 0; i > 0; --i) {
        if (k < m && s[i-1] == t[m-1-k])
            ++k;

        ss[i-1] = k;
    }

    size_t k = 0;
    for (size_t i = 0, j = 0; i <= n; ++i) {
        while (j <= n && ps[i] + ss[j] >= m)
            ++j;

        k = std::max(k, j - i - 1);
    }

    std::cout << k << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
