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
        p[i+1] = p[i] + (s[i] == 'H');

    unsigned v = ~0u;
    {
        for (size_t h = p[n], i = h; i <= n; ++i)
            v = std::min<unsigned>(v, h - (p[i] - p[i-h]));

        for (size_t t = n - p[n], i = t; i <= n; ++i)
            v = std::min<unsigned>(v, p[i] - p[i-t]);
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
