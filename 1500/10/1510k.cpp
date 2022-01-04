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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

constexpr unsigned oo = ~0u;

unsigned solve_a(std::vector<unsigned>& p, unsigned k);
unsigned solve_h(std::vector<unsigned>& p, unsigned k);

unsigned solve_a(std::vector<unsigned>& p, unsigned k)
{
    if (std::is_sorted(p.cbegin(), p.cend()))
        return k;

    const size_t n = p.size();
    if (k > n)
        return oo;

    for (size_t i = 0; i < n; i += 2)
        std::swap(p[i], p[i+1]);

    return solve_h(p, k + 1);
}

unsigned solve_h(std::vector<unsigned>& p, unsigned k)
{
    if (std::is_sorted(p.cbegin(), p.cend()))
        return k;

    const size_t n = p.size(), m = n / 2;
    if (k > n)
        return oo;

    for (size_t i = 0; i < m; ++i)
        std::swap(p[i], p[m+i]);

    return solve_a(p, k + 1);
}

void solve(const std::vector<unsigned>& p)
{
    auto p1 = p;
    const unsigned k1 = solve_a(p1, 0);

    auto p2 = p;
    const unsigned k2 = solve_h(p2, 0);

    if (k1 != oo || k2 != oo)
        return answer(std::min(k1, k2));

    no_answer();
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(2 * n);
    std::cin >> p;

    solve(p);

    return 0;
}
