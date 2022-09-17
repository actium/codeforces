#include <iostream>
#include <string>
#include <vector>

void answer(unsigned u, const std::vector<size_t>& v)
{
    std::cout << u << ' ' << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> x[26];
    for (size_t i = 0; i < n; ++i)
        x[s[i]-'a'].push_back(i);

    std::vector<size_t> p;
    if (s.front() > s.back()) {
        for (char c = s.front(); c >= s.back(); --c)
            p.insert(p.end(), x[c-'a'].cbegin(), x[c-'a'].cend());
    } else {
        for (char c = s.front(); c <= s.back(); ++c)
            p.insert(p.end(), x[c-'a'].cbegin(), x[c-'a'].cend());
    }

    answer(std::abs(s.front() - s.back()), p);
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
