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

void solve(const std::string& s)
{
    const size_t n = s.length() + 1;

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::vector<std::pair<unsigned, unsigned>> q(n);
    for (size_t i = 0; i < n - 1; ++i)
        q[i] = std::make_pair(s[i], 0);

    std::sort(p.begin(), p.end(), [&q](size_t x, size_t y) { return q[x].first < q[y].first; });

    std::vector<unsigned> c(n);
    for (unsigned k = 1; k < n; k *= 2) {
        c[p[0]] = 0;
        for (size_t i = 1; i < n; ++i)
            c[p[i]] = c[p[i-1]] + (q[p[i]] != q[p[i-1]]);

        for (size_t i = 0; i < n; ++i)
            q[i] = std::make_pair(c[i], c[(i + k) % n]);

        std::sort(p.begin(), p.end(), [&q](size_t x, size_t y) { return q[x] < q[y]; });
    }

    answer(p);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
