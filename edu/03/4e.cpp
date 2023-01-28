#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << "Yes" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "No" << '\n';
}

std::vector<unsigned> z(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> z(n);
    for (size_t i = 1, j = 0; i < n; ++i) {
        unsigned& p = z[i];
        if (j + z[j] > i)
            p = std::min<unsigned>(j + z[j] - i, z[i - j]);

        while (i + p < n && s[p] == s[i + p])
            ++p;

        if (j + z[j] < i + p)
            j = i;
    }
    return z;
}

void solve(const std::string& s, const std::string& t)
{
    const size_t m = s.length(), n = 2 * m + 1;
    if (t.length() != m)
        return no_answer();

    std::string v;
    v.reserve(n);
    v.append(t); v.push_back(' '); v.append(s);

    std::string w;
    w.reserve(n);
    w.append(s); w.push_back(' '); w.append(t.rbegin(), t.rend());

    const std::vector<unsigned> z1 = z(v), z2 = z(w);
    for (size_t i = m + 1; i < n; ++i) {
        if (z1[i] != n - i)
            continue;

        if (z2[m + 1] >= m - z1[i])
            return answer(i - (m + 1));
    }

    no_answer();
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
