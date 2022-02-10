#include <algorithm>
#include <iostream>
#include <vector>

struct Team {
    std::string n;
    unsigned p = 0;
    unsigned s = 0;
    unsigned c = 0;
};

void answer(const std::vector<Team>& v)
{
    const char* separator = "";
    for (const Team& x : v)
        std::cout << x.n << '\n';
}

void solve(std::vector<Team>& t)
{
    const auto c = [](const Team& a, const Team& b) {
        if (a.p != b.p)
            return a.p > b.p;

        if (a.s + b.c != b.s + a.c)
            return a.s + b.c > b.s + a.c;

        return a.s > b.s;
    };

    std::sort(t.begin(), t.end(), c);
    t.resize(t.size() / 2);
    std::sort(t.begin(), t.end(), [](const Team& a, const Team& b) { return a.n < b.n; });

    answer(t);
}

int main()
{
    const auto split = [](const std::string& s, char d) {
        const size_t x = s.find(d);

        return std::make_pair(s.substr(0, x), s.substr(x + 1));
    };

    size_t n;
    std::cin >> n;

    std::vector<Team> t(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> t[i].n;

    for (size_t i = 0, k = n * (n - 1) / 2; i < k; ++i) {
        std::string m, s;
        std::cin >> m >> s;

        const auto tn = split(m, '-');
        Team& a = *std::find_if(t.begin(), t.end(), [&tn](const Team& x) { return x.n == tn.first; });
        Team& b = *std::find_if(t.begin(), t.end(), [&tn](const Team& x) { return x.n == tn.second; });

        const auto tp = split(s, ':');
        const unsigned p1 = std::stoi(tp.first);
        const unsigned p2 = std::stoi(tp.second);

        a.s += p1, a.c += p2;
        if (p1 > p2)
            a.p += 3;

        b.s += p2, b.c += p1;
        if (p2 > p1)
            b.p += 3;

        if (p1 == p2)
            ++a.p, ++b.p;
    }

    solve(t);

    return 0;
}
