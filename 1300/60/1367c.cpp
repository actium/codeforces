#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::string& s, size_t k)
{
    const size_t n = s.length();

    size_t count = 0;
    {
        const size_t x = s.find('1');
        if (x == std::string::npos || x > k) {
            s[0] = '1';
            ++count;
        }
    }
    {
        const std::string p(2*k+1, '0');
        for (size_t x = s.find(p); x != std::string::npos; x = s.find(p, x + k)) {
            s[x+k] = '1';
            ++count;
        }
    }
    {
        const size_t x = s.rfind('1');
        if (x == std::string::npos || x+k < n-1) {
            ++count;
        }
    }
    answer(count);
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

