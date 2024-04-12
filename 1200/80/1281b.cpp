#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "---" << '\n';
}

void solve(std::string& s, const std::string& t)
{
    const size_t n = s.length();

    std::string p = s;
    std::sort(p.begin(), p.end());

    for (size_t i = 0; i < n; ++i) {
        if (p[i] < s[i]) {
            const size_t x = s.rfind(p[i]);
            std::swap(s[i], s[x]);
            break;
        }
    }

    s < t ? answer(s) : no_answer();
}

void test_case()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
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
