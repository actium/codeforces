#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << ":(" << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    if (n % 2 != 0)
        return no_answer();

    std::vector<size_t> p[3];
    for (size_t i = 0; i < n; ++i) {
        switch (s[i]) {
            case '(': p[0].push_back(i); break;
            case ')': p[1].push_back(i); break;
            case '?': p[2].push_back(i); break;
        }
    }

    if (p[0].size() > n / 2 || p[1].size() > n / 2)
        return no_answer();

    for (size_t k = n / 2 - p[1].size(); k != 0; --k) {
        s[p[2].back()] = ')';
        p[2].pop_back();
    }
    for (size_t k = n / 2 - p[0].size(); k != 0; --k) {
        s[p[2].back()] = '(';
        p[2].pop_back();
    }

    int b = 0;
    for (size_t i = 0; i < n; ++i) {
        b += (s[i] == '(' ? 1 : -1);
        if (b < 0 || (b == 0) != (i + 1 == n))
            return no_answer();
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
