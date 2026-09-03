#include <iostream>

unsigned query(unsigned u, unsigned v, unsigned d)
{
    std::cout << '?' << ' ' << u << ' ' << v << ' ' << d << std::endl;

    unsigned r;
    std::cin >> r;
    return r;
}

void answer(unsigned u, unsigned v, unsigned d)
{
    std::cout << '!' << ' ' << u << ' ' << v << ' ' << d << std::endl;
}

void solve(unsigned n)
{
    const auto search = [n](unsigned s, unsigned t, unsigned d) {
        std::pair<unsigned, unsigned> p = { t, d };
        for (unsigned x = 1; x <= n; ++x) {
            if (x == s || x == t || query(s, x, p.second + 1) == 0)
                continue;

            p = std::make_pair(x, p.second + 1);
            while (query(s, x, p.second + 1) == 1)
                ++p.second;
        }
        return p;
    };

    const auto p = search(1, 1, 0), q = search(p.first, 1, p.second);
    answer(p.first, q.first, q.second);
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
