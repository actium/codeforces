#include <algorithm>
#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(integer a, integer b)
{
    std::string s = std::to_string(a);
    std::sort(s.begin(), s.end());
    for (size_t i = 0; i < s.length(); ++i) {
        const auto it = std::upper_bound(s.begin() + i + 1, s.end(), s[i]);
        if (it == s.end())
            continue;

        std::string t = s;
        std::swap(t[i], t[it-s.begin()]);
        std::sort(t.begin() + i + 1, t.end());

        if (std::stoull(t) <= b) {
            s = t;
            --i;
        }
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
