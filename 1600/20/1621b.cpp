#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Segment {
    unsigned l;
    unsigned r;
    unsigned c;
};

std::istream& operator >>(std::istream& input, Segment& s)
{
    return input >> s.l >> s.r >> s.c;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<Segment>& s)
{
    const size_t n = s.size();

    const auto evaluate = [&](size_t u, size_t v) {
        return u == v ? s[u].c : s[u].c + s[v].c;
    };

    size_t u = 0, v = 0, w = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i].l < s[u].l || s[i].l == s[u].l && s[i].c < s[u].c)
            u = i;

        if (s[i].r > s[v].r || s[i].r == s[v].r && s[i].c < s[v].c)
            v = i;

        if (w != n && (s[w].l != s[u].l || s[w].r != s[v].r))
            w = n;

        if (s[i].l == s[u].l && s[i].r == s[v].r && (w == n || s[i].c < s[w].c))
            w = i;

        answer(std::min(evaluate(u, v), w != n ? s[w].c : ~0u));
    }
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<Segment> s(n);
    std::cin >> s;

    solve(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
