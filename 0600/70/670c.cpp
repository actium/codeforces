#include <array>
#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << 1+v << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<unsigned>& c)
{
    const size_t m = b.size();

    std::map<unsigned, unsigned> f;
    for (const unsigned q : a)
        ++f[q];

    std::array<unsigned, 3> x = { f[b[0]], f[c[0]], 0 };
    for (size_t i = 1; i < m; ++i)
        x = std::max(x, { f[b[i]], f[c[i]], i });

    answer(x[2]);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> b(m), c(m);
    std::cin >> b >> c;

    solve(a, b, c);

    return 0;
}

