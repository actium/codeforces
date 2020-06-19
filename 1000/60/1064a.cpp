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

void solve(std::array<size_t, 3>& d)
{
    std::sort(d.begin(), d.end());

    if (d[0] + d[1] > d[2])
        return answer(0);

    answer(d[2] - d[1] - d[0] + 1);
}

int main()
{
    std::array<size_t, 3> d;
    std::cin >> d;

    solve(d);

    return 0;
}

