#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

unsigned z_max(const std::string& s, size_t b)
{
    const size_t n = s.length() - b;

    unsigned x = 0;

    std::vector<unsigned> z(n);
    for (size_t i = 1, j = 0; i < n; ++i) {
        unsigned& p = z[i];
        if (j + z[j] > i)
            p = std::min<unsigned>(j + z[j] - i, z[i - j]);

        while (i + p < n && s[b + p] == s[b + i + p])
            ++p;

        if (j + z[j] < i + p)
            j = i;

        x = std::max(x, p);
    }

    return x;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    integer q = 0;
    for (size_t i = 0; i < n; ++i) {
        const integer a = z_max(s, i), k = n - i;
        q += (k - a) * (k + a + 1) / 2;
    }

    answer(q);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
