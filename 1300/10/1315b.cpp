#include <iostream>
#include <string>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b, unsigned p, const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> ss(n);
    for (size_t i = 1; i < n; ++i) {
        if (i != 1 && s[n-i-1] == s[n-i])
            continue;

        if (s[n-i-1] == 'A' && p >= a) {
            p -= a;
            continue;
        }
        if (s[n-i-1] == 'B' && p >= b) {
            p -= b;
            continue;
        }

        return answer(n - i + 1);
    }

    answer(1);
}

void test_case()
{
    unsigned a, b, p;
    std::cin >> a >> b >> p;

    std::string s;
    std::cin >> s;

    solve(a, b, p, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

