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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::array<unsigned, 3>& p, size_t d)
{
    std::sort(p.begin(), p.end());

    const size_t d1 = p[1] - p[0];
    const size_t d2 = p[2] - p[1];

    answer((d > d1 ? d - d1 : 0) + (d > d2 ? d - d2 : 0));
}

int main()
{
    std::array<unsigned, 3> p;
    std::cin >> p;

    size_t d;
    std::cin >> d;

    solve(p, d);

    return 0;
}

