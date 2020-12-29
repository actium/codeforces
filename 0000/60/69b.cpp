#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct S {
    unsigned l;
    unsigned r;
    unsigned t;
    unsigned c;
};

std::istream& operator >>(std::istream& input, S& v)
{
    return input >> v.l >> v.r >> v.t >> v.c;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(size_t n, const std::vector<S>& s)
{
    const size_t m = s.size();

    std::vector<std::vector<size_t>> p(n);
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = s[i].l - 1; j < s[i].r; ++j)
            p[j].push_back(i);
    }

    const auto compare = [&s](size_t a, size_t b) {
        return s[a].t == s[b].t ? a < b : s[a].t < s[b].t;
    };

    unsigned c = 0;
    for (size_t i = 0; i < n; ++i) {
        if (p[i].empty())
            continue;

        std::sort(p[i].begin(), p[i].end(), compare);

        c += s[p[i].front()].c;
    }

    answer(c);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<S> s(m);
    std::cin >> s;

    solve(n, s);

    return 0;
}

