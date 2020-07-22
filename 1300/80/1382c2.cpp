#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size();

    for (const size_t x : v)
        std::cout << ' ' << 1+x;

    std::cout << '\n';
}

void solve(std::string& a, const std::string& b)
{
    const size_t n = a.size();

    std::vector<size_t> p;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] != a[0]) {
            p.push_back(i-1);
            a[0] ^= 1;
        }
    }
    for (size_t i = 1; i <= n; ++i) {
        if (b[n-i] != a[0]) {
            p.push_back(n-i);
            a[0] ^= 1;
        }
    }

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

