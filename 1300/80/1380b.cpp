#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::unordered_map<char, unsigned> f;
    for (const char c : s)
        ++f[c];

    const char x = std::max_element(f.cbegin(), f.cend(), [](const std::pair<char, unsigned>& a, const std::pair<char, unsigned>& b) { return a.second < b.second; })->first;
    switch (x) {
        case 'R': return answer(std::string(n, 'P'));
        case 'P': return answer(std::string(n, 'S'));
        case 'S': return answer(std::string(n, 'R'));
    }
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

