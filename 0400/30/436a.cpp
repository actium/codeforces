#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Candy {
    unsigned t;
    unsigned h;
    unsigned m;
};

std::istream& operator >>(std::istream& input, Candy& c)
{
    return input >> c.t >> c.h >> c.m;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned consume(std::multiset<std::pair<unsigned, unsigned>>& s, unsigned h)
{
    auto x = s.begin();
    for (auto it = std::next(x); it != s.end() && it->first <= h; ++it) {
        if (it->second >= x->second)
            x = it;
    }

    const unsigned m = x->second;
    s.erase(x);
    return m;
}

unsigned test(std::multiset<std::pair<unsigned, unsigned>> u, std::multiset<std::pair<unsigned, unsigned>> v, unsigned h)
{
    unsigned k = 0;
    while (!u.empty() && h >= u.begin()->first) {
        h += consume(u, h);
        ++k;

        if (v.empty() || h < v.begin()->first)
            break;

        h += consume(v, h);
        ++k;
    }
    return k;
}

void solve(std::vector<Candy>& c, unsigned x)
{
    const size_t n = c.size();

    std::multiset<std::pair<unsigned, unsigned>> s[2];
    for (size_t i = 0; i < n; ++i)
        s[c[i].t].emplace(c[i].h, c[i].m);

    answer(std::max(test(s[0], s[1], x), test(s[1], s[0], x)));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<Candy> c(n);
    std::cin >> c;

    solve(c, x);

    return 0;
}
