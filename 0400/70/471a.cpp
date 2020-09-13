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
    constexpr const char* s[3] = { "Alien", "Elephant", "Bear" };
    std::cout << s[v] << '\n';
}

void solve(std::array<unsigned, 6>& l)
{
    std::sort(l.begin(), l.end());

    if (l[0] == l[3])
        return answer(l[4] == l[5] ? 1 : 2);

    if (l[1] == l[4])
        return answer(2);

    if (l[2] == l[5])
        return answer(l[0] == l[1] ? 1 : 2);

    answer(0);
}

int main()
{
    std::array<unsigned, 6> l;
    std::cin >> l;

    solve(l);

    return 0;
}

