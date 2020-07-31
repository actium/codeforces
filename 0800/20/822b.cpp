#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();
    const size_t m = t.length();

    std::vector<unsigned> d(m - n + 1);
    for (size_t i = 0; i <= m - n; ++i) {
        for (size_t j = 0; j < n; ++j)
            d[i] += (s[j] != t[i+j]);
    }

    const size_t x = std::min_element(d.cbegin(), d.cend()) - d.cbegin();

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] != t[x+i])
            p.push_back(i);
    }

    answer(p);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::string t;
    std::cin >> t;

    solve(s, t);

    return 0;
}

