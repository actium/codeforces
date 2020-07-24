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

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<unsigned> f(k);
    for (const unsigned x : a)
        ++f[x-1];

    unsigned c = 0;
    for (size_t i = 0; i < k; ++i)
        c += f[i] / 2 * 2;

    answer(c + (n + 1 - c) / 2);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

