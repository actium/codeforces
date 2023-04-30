#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const integer n = s.length();

    integer k = 0, c = 0;
    for (integer i = 0; i < 2 * n; ++i) {
        if (s[i % n] == '1') {
            ++c;
        } else {
            k = std::max(k, c);
            c = 0;
        }
    }
    k = std::max(k, c);

    if (k >= n)
        return answer(n * n);

    const integer x = (k + 1) / 2, y = k / 2 + 1;
    answer(x * y);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
