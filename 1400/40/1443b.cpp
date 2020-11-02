#include <iostream>
#include <string>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, unsigned a, unsigned b)
{
    const size_t n = s.length();

    size_t i = s.find('1');
    if (i == std::string::npos)
        return answer(0);

    std::vector<unsigned> d;
    for (unsigned k = 1; ++i < n; ++k) {
        if (s[i] != s[i-1]) {
            d.push_back(k);
            k = 0;
        }
    }

    unsigned c = a;
    for (size_t i = 2, m = d.size(); i < m; i += 2)
        c += std::min(d[i-1] * b, a);

    answer(c);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    std::string s;
    std::cin >> s;

    solve(s + '0', a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

