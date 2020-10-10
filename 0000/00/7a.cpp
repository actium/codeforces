#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::array<std::string, 8>& b)
{
    unsigned k = 0;
    for (size_t i = 0; i < 8; ++i) {
        if (b[i].find('W') == std::string::npos)
            ++k;
    }

    if (k < 8) {
        size_t r = 0;
        while (b[r].find('W') == std::string::npos)
            ++r;

        for (size_t i = 0; i < 8; ++i) {
            if (b[r][i] == 'B')
                ++k;
        }
    }

    answer(k);
}

int main()
{
    std::array<std::string, 8> b;
    std::cin >> b;

    solve(b);

    return 0;
}

