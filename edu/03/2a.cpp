#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> z(n);
    for (size_t i = 1; i < n; ++i) {
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            ++z[i];
    }

    answer(z);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
