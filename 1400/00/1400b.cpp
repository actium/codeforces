#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned p, unsigned f, unsigned ks, unsigned kw, unsigned s, unsigned w)
{
    if (s > w) {
        std::swap(s, w);
        std::swap(ks, kw);
    }

    unsigned k = 0;
    for (unsigned pks = 0, ub = std::min(p / s, ks); pks <= ub; ++pks) {
        const unsigned pkw = std::min((p - pks * s) / w, kw);
        const unsigned fks = std::min(f / s, ks - pks);
        const unsigned fkw = std::min((f - fks * s) / w, kw - pkw);

        k = std::max(k, pks + pkw + fks + fkw);
    }

    answer(k);
}

void test_case()
{
    unsigned p, f;
    std::cin >> p >> f;

    unsigned ks, kw;
    std::cin >> ks >> kw;

    unsigned s, w;
    std::cin >> s >> w;

    solve(p, f, ks, kw, s, w);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

