#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, size_t k)
{
    const size_t n = s.length();

    std::sort(s.begin(), s.end());

    std::string t(1, s[k-1]);
    if (t[0] != s[0])
        return answer(t);

    if (s[n-1] == s[k]) {
        t.append((n - 1) / k, s[k]);
    } else {
        t.append(s.substr(k));
    }

    answer(t);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
