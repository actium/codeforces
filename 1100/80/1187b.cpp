#include <iostream>
#include <string>
#include <vector>

std::vector<size_t> p[26];

void preprocess(const std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 0; i < n; ++i)
        p[s[i]-'a'].push_back(i);
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& t)
{
    size_t d[26] = {}, k = 0;
    for (const char c : t) {
        const size_t x = c - 'a';
        k = std::max(k, p[x][d[x]++]);
    }

    answer(k + 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    preprocess(s);

    size_t m;
    std::cin >> m;

    for (size_t i = 0; i < m; ++i) {
        std::string t;
        std::cin >> t;

        solve(t);
    }

    return 0;
}

