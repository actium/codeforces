#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t m = s.length(), n = 2 * m;

    std::string v;
    v.reserve(n);
    v.append(s); v.append(s);

    std::vector<unsigned> z(n);
    for (size_t i = 1, j = 0; i < n; ++i) {
        if (i < j + z[j])
            z[i] = std::min<unsigned>(j + z[j] - i, z[i - j]);

        while (i + z[i] < n && v[i + z[i]] == v[z[i]])
            ++z[i];

        if (j + z[j] < i + z[i])
            j = i;
    }

    unsigned k = 1;
    for (size_t i = 0; i < m; ++i) {
        if (z[i] < m && v[i + z[i]] < v[z[i]])
            ++k;
    }

    answer(k);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
