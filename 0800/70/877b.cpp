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

    std::vector<unsigned> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + (s[i] == 'a');

    unsigned x = 0;
    for (size_t i = 0; i <= n; ++i) {
        for (size_t j = 0; j <= i; ++j)
            x = std::max<unsigned>(x, 2 * (p[j] - p[i]) + p[n] - p[0] + (i - j));
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
