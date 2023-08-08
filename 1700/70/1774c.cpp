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

void solve(unsigned n, const std::string& s)
{
    std::vector<unsigned> c(n - 1);
    c[0] = 1;
    for (unsigned i = 1, k = 1; i < n - 1; ++i) {
        if (s[i] == s[i-1]) {
            c[i] = c[i-1];
            ++k;
        } else {
            c[i] = c[i-1] + k;
            k = 1;
        }
    }

    answer(c);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(n, s);
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
