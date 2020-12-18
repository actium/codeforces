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

void solve(const std::array<std::array<bool, 4>, 4>& c)
{
    for (size_t i = 0; i < 4; ++i) {
        if (!c[i][3])
            continue;

        if (c[i][0] || c[i][1] || c[i][2])
            return answer(true);

        if (c[(i + 1) % 4][0] || c[(i + 2) % 4][1] || c[(i + 3) % 4][2])
            return answer(true);
    }

    answer(false);
}

int main()
{
    std::array<std::array<bool, 4>, 4> c;
    std::cin >> c;

    solve(c);

    return 0;
}

