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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& c, size_t n)
{
    std::vector<unsigned> f(n);
    for (const unsigned x : c)
        ++f[x-1];

    answer(*std::min_element(f.cbegin(), f.cend()));
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> c(m);
    std::cin >> c;

    solve(c, n);

    return 0;
}

