#include <array>
#include <iostream>
#include <numeric>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::array<unsigned, 5>& c)
{
    const unsigned s = std::accumulate(c.cbegin(), c.cend(), 0u);
    answer(s > 0 && s % 5 == 0 ? s / 5 : -1);
}

int main()
{
    std::array<unsigned, 5> c;
    std::cin >> c;

    solve(c);

    return 0;
}

