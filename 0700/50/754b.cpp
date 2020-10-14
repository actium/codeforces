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

unsigned count(char c)
{
    if (c == 'x')
        return 2;

    if (c == '.')
        return 1;

    return 0;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::array<std::string, 4>& a)
{
    for (size_t i = 0; i < 4; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            if (count(a[i][j]) + count(a[i][j+1]) + count(a[i][j+2]) == 5)
                return answer(true);
        }
    }

    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 4; ++j) {
            if (count(a[i][j]) + count(a[i+1][j]) + count(a[i+2][j]) == 5)
                return answer(true);
        }
    }

    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 2; ++j) {
            if (count(a[i][j]) + count(a[i+1][j+1]) + count(a[i+2][j+2]) == 5)
                return answer(true);

            if (count(a[i][j+2]) + count(a[i+1][j+1]) + count(a[i+2][j]) == 5)
                return answer(true);
        }
    }

    answer(false);
}

int main()
{
    std::array<std::string, 4> a;
    std::cin >> a;

    solve(a);

    return 0;
}

