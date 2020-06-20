#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s, std::string& t)
{
    const size_t n = s.length();
    const size_t m = t.length();

    std::sort(t.rbegin(), t.rend());

    for (size_t i = 0, j = 0; i < n && j < m; ++i) {
        if (s[i] < t[j])
            s[i] = t[j++];
    }

    answer(s);
}

int main()
{
    std::string s;
    std::cin >> s;

    std::string t;
    std::cin >> t;

    solve(s, t);

    return 0;
}

