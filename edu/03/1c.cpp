#include <iostream>
#include <string>
#include <vector>

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

void solve(const std::string& t, const std::string& p)
{
    const size_t n = t.length(), m = p.length();

    const auto check = [&](size_t x) {
        for (size_t i = 0; i < m; ++i) {
            if (p[i] != '?' && t[x+i] != p[i])
                return false;
        }
        return true;
    };

    std::vector<size_t> x;
    for (size_t i = 0; i + m <= n; ++i) {
        if (check(i))
            x.push_back(i);
    }

    answer(x);
}

void test_case()
{
    std::string t, p;
    std::cin >> t >> p;

    solve(t, p);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
