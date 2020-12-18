#include <array>
#include <iostream>
#include <string>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "A", "B" };
    std::cout << s[v] << '\n';
}

void solve(const std::array<std::string, 8>& g)
{
    size_t a = 8, b = 8;
    for (size_t c = 0; c < 8; ++c) {
        for (size_t r = 0; r < 8 && g[r][c] != 'B'; ++r) {
            if (g[r][c] == 'W')
                a = std::min(a, r);
        }
        for (size_t r = 0; r < 8 && g[7-r][c] != 'W'; ++r) {
            if (g[7-r][c] == 'B')
                b = std::min(b, r);
        }
    }

    answer(b < a);
}

int main()
{
    std::array<std::string, 8> g;
    std::cin >> g;

    solve(g);

    return 0;
}

