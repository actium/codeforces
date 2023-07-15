#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<int> p(26, -1);
    for (unsigned i = 0; i < 26; ++i) {
        for (size_t j = 0, c = -1; j < n; ++j) {
            if (s[j] - 'a' == i)
                c = j;

            p[i] = std::max<int>(p[i], j - c);
        }
    }

    unsigned k = ~0u;
    for (unsigned i = 0; i < 26; ++i) {
        if (p[i] == -1)
            continue;

        if (p[i] == 0)
            return answer(0);

        k = std::min(k, 32u - __builtin_clz(p[i]));
    }

    answer(k);
}

void test_case()
{
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
