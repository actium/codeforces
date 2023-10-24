#include <iostream>
#include <map>
#include <numeric>
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

    std::vector<unsigned> q(n);
    {
        std::map<std::pair<unsigned, unsigned>, unsigned> f;

        unsigned d = 0, k = 0;
        for (size_t i = 0; i < n; ++i) {
            ++(s[i] == 'D' ? d : k);

            const unsigned g = std::max<unsigned>(std::gcd(d, k), 1);
            q[i] = ++f[std::make_pair(d / g, k / g)];
        }
    }

    answer(q);
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
