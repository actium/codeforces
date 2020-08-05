#include <iostream>
#include <string>
#include <vector>

void answer(unsigned k, const std::vector<unsigned>& p)
{
    std::cout << k << '\n';

    const char* separator = "";
    for (const unsigned x : p) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    std::vector<unsigned> p(n);

    std::vector<unsigned> q[2];
    for (size_t i = 0; i < n; ++i) {
        const size_t d = s[i] - '0';

        if (q[d].empty()) {
            p[i] = ++k;
        } else {
            p[i] = q[d].back();
            q[d].pop_back();
        }

        q[d^1].push_back(p[i]);
    }

    answer(k, p);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

