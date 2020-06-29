#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, std::vector<int>& b)
{
    const size_t m = b.size();

    std::map<char, size_t> x;
    for (const char c : s)
        ++x[c];

    std::string t(m, ' ');
    for (size_t i = 0; i < m; ) {
        const size_t c = std::count(b.cbegin(), b.cend(), 0);
        while (x.rbegin()->second < c)
            x.erase(std::prev(x.end()));

        std::vector<int> d;
        for (size_t j = 0; j < m; ++j) {
            if (b[j] == 0) {
                t[j] = x.rbegin()->first;
                d.push_back(j);
                b[j] = -1;
            }
        }

        for (int j = 0; j < m; ++j) {
            if (b[j] == -1)
                continue;

            for (const int a : d)
                b[j] -= abs(j - a);
        }

        x.erase(std::prev(x.end()));

        i += c;
    }

    answer(t);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    size_t m;
    std::cin >> m;

    std::vector<int> b(m);
    std::cin >> b;

    solve(s, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

