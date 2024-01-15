#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, size_t k)
{
    const size_t n = s.length();

    char c = s[0], b = 'z';
    for (size_t i = 0; i < n; ++i) {
        if (s[i] >= 'a' + k) {
            b = s[i];
            break;
        }
        c = std::max(c, s[i]);
    }

    for (size_t i = 0, d = k - std::min<size_t>(c - 'a', k); i < n; ++i) {
        if (s[i] > b)
            continue;

        if (s[i] > b - d)
            s[i] = b - d;

        if (s[i] + k > c && s[i] <= c)
            s[i] = 'a' + k < c ? c - k : 'a';
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
