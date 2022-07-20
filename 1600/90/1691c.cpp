#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned f(const std::string& s)
{
    const size_t n = s.length();

    unsigned c = 0;
    for (size_t i = 1; i < n; ++i) {
        c += (s[i-1] - '0') * 10 + (s[i] - '0');
    }
    return c;
}

void solve(std::string& s, size_t k)
{
    const size_t n = s.length(), z = n - 1;

    const size_t x1 = s.rfind('1');
    if (x1 != std::string::npos && x1 + k >= z) {
        std::swap(s[x1], s[z]);
        k -= z - x1;
    }

    const size_t x2 = s.find('1');
    if (x2 != std::string::npos && x2 < z && x2 <= k) {
        std::swap(s[0], s[x2]);
    }

    answer(f(s));
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

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
