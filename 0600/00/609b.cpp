#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, size_t m)
{
    const size_t n = a.size();

    std::vector<unsigned> f(m);
    for (const unsigned x : a)
        ++f[x-1];

    unsigned long long k = 0;
    for (size_t i = 0; i < m; ++i)
        k += f[i] * (n - f[i]);

    answer(k / 2);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);

    return 0;
}

