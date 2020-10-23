#include <iostream>
#include <string>
#include <vector>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::string& s, const std::string& t)
{
    const size_t n = s.length();

    std::vector<size_t> c;
    for (size_t i = 0; i < n; ++i) {
        size_t j = s.find(t[i], i);
        if (j == std::string::npos)
            return no_answer();

        while (j > i) {
            std::swap(s[j-1], s[j]);
            c.push_back(j--);
        }
    }

    answer(c);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}

