#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = t.length();

    size_t a = 0;
    for (size_t i = 0; i < n && s[i] == t[i]; ++i)
        ++a;

    size_t z = 0;
    for (size_t i = n; i > 0 && s[i] == t[i-1]; --i)
        ++z;

    std::vector<size_t> p;
    for (size_t x = n - z; x <= a; ++x)
        p.push_back(x);

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
