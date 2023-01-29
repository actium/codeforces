#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t m = s.length(), n = 2 * m + 1;

    std::string v;
    v.reserve(n);
    v.append(s); v.push_back(' '); v.append(s.rbegin(), s.rend());

    std::vector<unsigned> z(n);
    for (size_t i = 1, j = 0; i < n; ++i) {
        unsigned& p = z[i];
        if (j + z[j] > i)
            p = std::min<unsigned>(j + z[j] - i, z[i - j]);

        while (i + p < n && v[p] == v[i + p])
            ++p;

        if (j + z[j] < i + p)
            j = i;
    }

    size_t i = m + 1;
    while (z[i] != n - i)
        ++i;

    answer(z[i]);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
