#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t k)
{
    std::string a = s;
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());

    std::string t = s.substr(0, k);
    if (k > s.length()) {
        t.resize(k, a[0]);
    } else {
        auto it = t.rbegin();
        while (it != t.rend() && *it == a.back())
            *it++ = a[0];

        *it = a[a.find(*it) + 1];
    }

    answer(t);
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
