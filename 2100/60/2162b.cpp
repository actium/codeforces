#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

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

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0')
            p.push_back(i);
    }

    answer(p);
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
