#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, std::string& t)
{
    std::string r = s + t;
    for (unsigned i = 0; i < 2; ++i) {
        const size_t k = s.length(), m = t.length(), n = k + 1 + m;

        std::string v;
        v.reserve(n);
        v.append(s); v.push_back(' '); v.append(t);

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

        std::string q;
        for (size_t i = k + 1; i < n && q.empty(); ++i) {
            if (z[i] == n - i)
                q = t + s.substr(z[i]);

            if (z[i] == k)
                q = t;
        }

        if (!q.empty() && q.length() < r.length())
            std::swap(r, q);

        std::swap(s, t);
    }

    answer(r);
}

void test_case()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
