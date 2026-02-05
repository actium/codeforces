#include <iostream>
#include <string>
#include <vector>

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned f[2] = {};
    for (const char c : s)
        ++f[c-'0'];

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if ((s[i] == '0') != (i < f[0]))
            p.push_back(i);
    }

    if (p.empty()) {
        std::cout << "Bob" << '\n';
    } else {
        std::cout << "Alice" << '\n';
        std::cout << p.size() << '\n';
        for (const size_t x : p)
            std::cout << 1 + x << " \n"[x == p.back()];
    }
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
