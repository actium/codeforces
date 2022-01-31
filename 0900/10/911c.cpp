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

void solve(const std::array<unsigned, 3>& k)
{
    if (std::count(k.cbegin(), k.cend(), 1) != 0)
        return answer(true);

    if (std::count(k.cbegin(), k.cend(), 2) > 1)
        return answer(true);

    if (std::count(k.cbegin(), k.cend(), 3) == 3)
        return answer(true);

    answer(std::count(k.cbegin(), k.cend(), 4) == 2 && std::count(k.cbegin(), k.cend(), 2) == 1);
}

int main()
{
    std::array<unsigned, 3> k;
    std::cin >> k;

    solve(k);

    return 0;
}
