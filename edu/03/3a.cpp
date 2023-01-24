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

    std::vector<unsigned> p(n);
    for (size_t i = 1, j = 0; i < n; ++i) {
        unsigned& z = p[i];
        if (j + p[j] > i)
            z = std::min<unsigned>(j + p[j] - i, p[i - j]);

        while (i + z < n && s[z] == s[i + z])
            ++z;

        if (j + p[j] < i + z)
            j = i;
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
