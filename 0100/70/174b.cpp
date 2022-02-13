#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    std::cout << "YES" << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::string& s)
{
    std::vector<std::string> t = { "" };
    for (const char c : s) {
        if (c == '.')
            t.emplace_back();
        else
            t.back().push_back(c);
    }

    const size_t n = t.size();
    if (n < 2 || t[n-1].length() > 3)
        return no_answer();

    for (size_t i = 0; i < n - 1; ++i) {
        if (t[i].length() < 1 || t[i].length() > 8)
            return no_answer();

        const size_t m = t[i+1].length();
        if (m == 0 || m == 1 && i != n-2)
            return no_answer();

        const size_t k = std::min<size_t>(m - 1, 3);
        t[i] += '.' + t[i+1].substr(0, k);
        t[i+1].erase(0, k);
    }
    t[n-2] += t[n-1];
    t.pop_back();

    answer(t);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
