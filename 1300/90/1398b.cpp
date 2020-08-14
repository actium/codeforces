#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> m;
    for (size_t i = s.find('1'); i != std::string::npos; i = s.find('1', i)) {
        unsigned c = 0;
        while (i < n && s[i] == '1')
            ++c, ++i;

        m.push_back(c);
    }

    std::sort(m.begin(), m.end(), std::greater<unsigned>());

    unsigned k = 0;
    for (size_t i = 0; i < m.size(); i += 2)
        k += m[i];

    answer(k);
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

