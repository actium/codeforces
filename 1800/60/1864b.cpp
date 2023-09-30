#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, size_t k)
{
    const size_t n = s.length();

    if (k % 2 == 0) {
        std::sort(s.begin(), s.end());
    } else {
        std::string t[2];
        for (size_t i = 0; i < n; ++i)
            t[i % 2].push_back(s[i]);

        std::sort(t[0].begin(), t[0].end());
        std::sort(t[1].begin(), t[1].end());

        for (size_t i = 0; i < n; ++i)
            s[i] = t[i % 2][i / 2];
    }

    answer(s);
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
