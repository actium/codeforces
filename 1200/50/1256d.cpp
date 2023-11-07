#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, integer k)
{
    const size_t n = s.length();

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0')
            p.push_back(i);
    }

    for (size_t i = 0, j = 0; i < n && j < p.size() && k > 0; j += (p[j] == i++)) {
        const size_t d = p[j] - i;
        if (s[i] == '1' && d <= k) {
            std::swap(s[i], s[p[j]]);
            k -= d;
            ++j;
        }
    }

    answer(s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
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
