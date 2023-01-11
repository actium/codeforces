#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void sort(std::vector<size_t>& p, const std::vector<unsigned>& c)
{
    const size_t n = p.size();

    std::vector<unsigned> x(1 + n);
    for (size_t i = 0; i < n; ++i)
        ++x[1 + c[i]];

    for (size_t i = 1; i < n; ++i)
        x[i] += x[i-1];

    std::vector<size_t> q(n);
    {
        for (const size_t i : p)
            q[x[c[i]]++] = i;
    }
    p = std::move(q);
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&s](size_t x, size_t y) { return s[x] < s[y]; });

    std::vector<unsigned> c(n);
    for (size_t i = 1; i < n; ++i)
        c[p[i]] = c[p[i-1]] + (s[p[i]] != s[p[i-1]]);

    for (unsigned k = 1; k < n; k *= 2) {
        for (size_t i = 0; i < n; ++i)
            p[i] = (p[i] - k + n) % n;

        sort(p, c);

        std::vector<unsigned> q(n);
        {
            size_t x = p[0];
            for (const size_t y : p) {
                q[y] = q[x] + (c[y] != c[x] || c[(y + k) % n] != c[(x + k) % n]);
                x = y;
            }
        }
        c = std::move(q);
    }

    answer(p);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    s.push_back(' ');
    solve(s);

    return 0;
}
