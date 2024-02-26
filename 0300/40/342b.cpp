#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Watch {
    unsigned t;
    unsigned l;
    unsigned r;
};

std::istream& operator >>(std::istream& input, Watch& w)
{
    return input >> w.t >> w.l >> w.r;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(unsigned s, unsigned f, const std::vector<Watch>& w)
{
    const size_t m = w.size();

    std::string p;
    for (size_t i = 0, t = 1; s != f; ++t) {
        if (i < m && w[i].t < t)
            ++i;

        if (s < f && (i == m || t < w[i].t || s + 1 < w[i].l || w[i].r < s)) {
            p.push_back('R');
            ++s;
            continue;
        }
        if (s > f && (i == m || t < w[i].t || s < w[i].l || w[i].r < s - 1)) {
            p.push_back('L');
            --s;
            continue;
        }
        p.push_back('X');
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    unsigned s, f;
    std::cin >> s >> f;

    std::vector<Watch> w(m);
    std::cin >> w;

    solve(s, f, w);

    return 0;
}
