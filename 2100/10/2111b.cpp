#include <iostream>
#include <vector>

constexpr unsigned s[] = {
    1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
};

struct Cube {
    unsigned w;
    unsigned l;
    unsigned h;
};

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(size_t n, const std::vector<Cube>& c)
{
    const size_t m = c.size();

    std::string p(m, '0');
    for (size_t i = 0; i < m; ++i) {
        if (s[n] > c[i].w || s[n] > c[i].l || s[n] > c[i].h)
            continue;

        if (s[n+1] <= c[i].w || s[n+1] <= c[i].l || s[n+1] <= c[i].h)
            p[i] = '1';
    }

    answer(p);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<Cube> c(m);
    for (size_t i = 0; i < m; ++i)
        std::cin >> c[i].w >> c[i].l >> c[i].h;

    solve(n, c);
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
