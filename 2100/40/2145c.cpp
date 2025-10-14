#include <iostream>
#include <map>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.size();

    int b = 0;
    for (const char c : s)
        b += (c == 'b' ? 1 : -1);

    size_t k = n;
    {
        std::map<int, size_t> x;
        x[0] = -1;
        for (size_t i = 0, d = 0; i < n; ++i) {
            d += (s[i] == 'a' ? 1 : -1);
            x[d] = i;

            const auto it = x.find(b + d);
            if (it != x.end())
                k = std::min(k, i - it->second);
        }
    }

    if (k != n)
        return answer(k);

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
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
