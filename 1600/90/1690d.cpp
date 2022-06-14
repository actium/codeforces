#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    unsigned c = 0;
    for (size_t i = 0; i < k; ++i)
        c += (s[i] == 'W');
    
    unsigned q = c;
    for (size_t i = k; i < n; ++i) {
        c -= (s[i-k] == 'W');
        c += (s[i] == 'W');

        q = std::min(q, c);
    }

    answer(q);
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
