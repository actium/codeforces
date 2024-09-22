#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s1, const std::string& s2, size_t t)
{
    const size_t n = s1.length();

    std::vector<size_t> x;
    for (size_t i = 0; i < n; ++i) {
        if (s1[i] == s2[i])
            x.push_back(i);
    }

    if (n - x.size() > 2 * t)
        return no_answer();

    std::string s(n, ' ');

    const auto update = [&](size_t i) {
        for (s[i] = 'a'; s[i] == s1[i] || s[i] == s2[i]; ++s[i]);
    };

    while (x.size() > n - t) {
        update(x.back());
        x.pop_back();
    }

    for (const size_t i : x)
        s[i] = s1[i];

    for (size_t i = 0, k1 = 0, k2 = 0; i < n; ++i) {
        if (s[i] != ' ')
            continue;

        if (x.size() + (k1 + k2) / 2 == n - t) {
            update(i);
            continue;
        }

        if (k1 == k2) {
            s[i] = s1[i];
            ++k1;
        } else {
            s[i] = s2[i];
            ++k2;
        }
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, t;
    std::cin >> n >> t;

    std::string s1, s2;
    std::cin >> s1 >> s2;

    solve(s1, s2, t);

    return 0;
}
