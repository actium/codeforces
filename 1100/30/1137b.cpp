#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t m = t.size();

    std::vector<unsigned> p(m);
    for (unsigned i = 1, j = 0; i < m; ++i) {
        if (t[i] == t[j]) {
            p[i] = ++j;
            continue;
        }

        if (j > 0) {
            j = p[j-1];
            --i;
        }
    }

    unsigned f[2] = {};
    for (const char c : s)
        ++f[c-'0'];

    std::string q;
    for (size_t i = 0; f[0] + f[1] != 0; --f[q.back()-'0']) {
        char c = t[i];
        if (f[c-'0'] == 0)
            c ^= 1;

        q.push_back(c);

        if (++i == m)
            i = p.back();
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
