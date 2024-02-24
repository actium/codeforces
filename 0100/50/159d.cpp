#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> p(n), q(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t d = 0; d <= i && i + d < n && s[i-d] == s[i+d]; ++d) {
            ++p[i+d];
            ++q[i-d];
        }
        for (size_t d = 0; d < i && i + d < n && s[i-1-d] == s[i+d]; ++d) {
            ++p[i+d];
            ++q[i-1-d];
        }
    }

    for (size_t i = 1; i < n; ++i)
        p[i] += p[i-1];

    integer k = 0;
    for (size_t i = 1; i < n; ++i)
        k += 1ull * p[i-1] * q[i];

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
