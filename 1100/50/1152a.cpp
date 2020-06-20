#include <iostream>
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
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    size_t fa[2] = {};
    for (const size_t x : a)
        ++fa[x % 2];

    size_t fb[2] = {};
    for (const size_t x : b)
        ++fb[x % 2];

    answer(std::min(fa[0], fb[1]) + std::min(fa[1], fb[0]));
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(a, b);

    return 0;
}

