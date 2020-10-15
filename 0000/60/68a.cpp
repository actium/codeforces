#include <algorithm>
#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::array<unsigned, 4>& p, unsigned a, unsigned b)
{
    const unsigned ub = std::min(b + 1, *std::min_element(p.cbegin(), p.cend()));

    answer(a < ub ? ub - a : 0);
}

int main()
{
    std::array<unsigned, 4> p;
    std::cin >> p;

    unsigned a, b;
    std::cin >> a >> b;

    solve(p, a, b);

    return 0;
}

