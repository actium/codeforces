#include <iostream>
#include <vector>

using integer = unsigned long long;

constexpr integer oo = ~integer(0);

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

integer evaluate(const std::vector<integer>& p, unsigned l)
{
    if (l == 0)
        return 0;

    const unsigned k = __builtin_clz(1) - __builtin_clz(l), d = 1 << k;
    return std::min(p[k+1], p[k] + evaluate(p, l - d));
}

void solve(const std::vector<unsigned>& c, unsigned l)
{
    std::vector<integer> p(c.begin(), c.end());
    p.resize(32, oo);
    for (size_t i = 1; i < 32; ++i)
        p[i] = std::min(p[i], 2 * p[i-1]);

    for (size_t i = 31; i > 0; --i)
        p[i-1] = std::min(p[i-1], p[i]);

    answer(evaluate(p, l));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned l;
    std::cin >> l;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c, l);

    return 0;
}
