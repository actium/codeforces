#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size();

    const char* separator = "\n";
    for (const size_t x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

std::vector<unsigned> z(const std::string& s)
{
    const size_t n = s.length();

    std::vector<unsigned> z(n);
    for (size_t i = 1, j = 0; i < n; ++i) {
        if (i < j + z[j])
            z[i] = std::min<unsigned>(j + z[j] - i, z[i - j]);

        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            ++z[i];

        if (j + z[j] < i + z[i])
            j = i;
    }
    return z;
}

void solve(const std::string& t, const std::string& p, unsigned k)
{
    const size_t m = p.length(), n = t.length() + 1 + m;

    std::string v;
    v.reserve(n);
    v.append(p); v.push_back(' '); v.append(t);

    std::string w;
    w.reserve(n);
    w.append(p.rbegin(), p.rend()); w.push_back(' '); w.append(t.rbegin(), t.rend());

    std::vector<size_t> x;
    {
        const std::vector<unsigned> z1 = z(v), z2 = z(w);
        for (size_t i = m + 1; i + m <= n; ++i) {
            if (z1[i] + k + z2[n-i+1] >= m)
                x.push_back(i - (m + 1));
        }
    }
    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string t, p;
    std::cin >> t >> p;

    unsigned k;
    std::cin >> k;

    solve(t, p, k);

    return 0;
}
