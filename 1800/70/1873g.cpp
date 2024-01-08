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

    std::vector<unsigned> p(1 + n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + (s[i] == 'A');

    unsigned k = 0;
    for (size_t i = 0, x = n; i < n; ++i) {
        if (s[i] == 'A')
            continue;

        if (x != n)
            k = std::max(k, p[x] + p[n] - p[i]);

        k = std::max(k, p[i]);
        k = std::max(k, p[n] - p[i]);

        x = i;
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
