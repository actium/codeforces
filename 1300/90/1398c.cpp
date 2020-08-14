#include <iostream>
#include <map>
#include <string>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::string& a)
{
    const size_t n = a.length();

    unsigned long long k = 0;

    std::map<unsigned, unsigned> f;
    ++f[0];

    unsigned s = 0;
    for (size_t i = 0; i < n; ++i) {
        s += a[i] - '0';
        k += f[s-(i+1)]++;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string a;
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

