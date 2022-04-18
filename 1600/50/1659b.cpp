#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& u, std::vector<unsigned>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::string& s, unsigned k)
{
    const size_t n = s.length();

    const char p = k % 2;

    std::vector<unsigned> q(n);
    for (size_t i = 0; i < n && k != 0; ++i) {
        if (s[i] - '0' == p) {
            q[i] = 1;
            --k;
        }
    }

    q.back() += k;

    for (size_t i = 0; i < n; ++i) {
        if (q[i] % 2 != p)
            s[i] ^= 1;
    }

    answer(s, q);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
