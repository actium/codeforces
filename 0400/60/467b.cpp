#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& x, size_t n, size_t k)
{
    const size_t m = x.size() - 1;

    unsigned c = 0;
    for (size_t i = 0; i < m; ++i)
        c += (__builtin_popcount(x[i] ^ x[m]) <= k);

    answer(c);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> x(m+1);
    std::cin >> x;

    solve(x, n, k);

    return 0;
}

