#include <iostream>
#include <vector>

char query(unsigned a, unsigned b, unsigned c, unsigned d)
{
    std::cout << '?' << ' ' << a << ' ' << b << ' ' << c << ' ' << d << std::endl;

    char r;
    std::cin >> r;
    return r;
}

void answer(unsigned x, unsigned y)
{
    std::cout << '!' << ' ' << x << ' ' << y << std::endl;
}

void solve(unsigned n)
{
    unsigned x = 0;
    for (unsigned i = 1; i < n; ++i) {
        if (query(x, x, i, i) == '<')
            x = i;
    }

    std::vector<unsigned> p = { x == 0 };
    for (unsigned i = p[0] + 1; i < n; ++i) {
        const char r = query(x, p[0], x, i);
        if (r == '<')
            p.clear();

        if (r == '=' || p.empty())
            p.push_back(i);
    }

    while (p.size() > 1) {
        if (query(p[0], p[0], p.back(), p.back()) == '>')
            p[0] = p.back();

        p.pop_back();
    }

    answer(x, p[0]);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
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
