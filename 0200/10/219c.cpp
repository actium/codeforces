#include <iostream>
#include <string>

void answer(unsigned x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    const auto f = [&](char x) {
        std::string t(1, x);
        for (size_t i = 1, j = (s[0] != x ? 0 : n); i < n; ++i) {
            if (s[i] != t[i-1]) {
                t.push_back(s[i]);
                continue;
            }

            if (k == 2) {
                t.push_back(s[i] ^ 'A' ^ 'B');
                continue;
            }

            if (j == i - 1) {
                t[j] = (t[j-1] == 'C' ? 'B' : 'C');
                t.push_back(s[i]);
            } else {
                t.push_back(t[i-1] == 'A' ? 'B' : 'A');
                j = i;
            }
        }
        return t;
    };

    const std::string u = f(s[0]), v = f(s[0] == 'A' ? 'B' : 'A');

    unsigned x = 0, y = 0;
    for (size_t i = 0; i < n; ++i) {
        x += (u[i] != s[i]);
        y += (v[i] != s[i]);
    }

    x < y ? answer(x, u) : answer(y, v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);

    return 0;
}
