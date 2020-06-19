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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::array<size_t, 4>& a)
{
    std::sort(a.begin(), a.end());

    answer(a[0] + a[3] == a[1] + a[2] || a[0] + a[1] + a[2] == a[3]);
}

int main()
{
    std::array<size_t, 4> a;
    std::cin >> a;

    solve(a);

    return 0;
}

