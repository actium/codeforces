#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();

    unsigned k = 0, q = 0;
    for (size_t i = 0; i < n; ++i) {
        k += (s[i] != t[i]);
        q += (s[i] != t[n-1-i]);
    }

    if (k < 2)
        return answer(k);

    if (q == 0)
        return answer(2);

    answer(std::min(2 * k - (k % 2 == 1), 2 * q - (q % 2 == 0)));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
