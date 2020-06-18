#include <algorithm>
#include <array>
#include <iostream>

using integer = long long;

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(std::array<integer, 3>& v)
{
    std::sort(v.begin(), v.end());

    const integer d = std::min(v[1] - v[0], v[2]);
    v[0] += d;
    v[2] -= d;
    answer(v[0] < v[1] ? v[0] : v[0] + v[2] / 2);
}

void test_case()
{
    std::array<integer, 3> v;
    std::cin >> v;

    solve(v);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

