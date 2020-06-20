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

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(std::array<int, 12>& a, int k)
{
    std::sort(a.begin(), a.end(), std::greater<int>());

    int i = 0;
    while (k > 0 && i < 12)
        k -= a[i++];

    answer(k <= 0 ? i : -1);
}

int main()
{
    int k;
    std::cin >> k;

    std::array<int, 12> a;
    std::cin >> a;

    solve(a, k);

    return 0;
}

