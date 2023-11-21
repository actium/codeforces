#include <iostream>
#include <string>
#include <vector>

using integer = long long;

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
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

    std::vector<integer> v(n, -1);
    for (size_t i = 0; i < n; ++i) {
        if (!p.empty()) {
            v[i] = n - i - p.back() - 1;
            if (i != 0)
                v[i] += v[i-1];

            p.pop_back();
        }
    }

    answer(v);
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
