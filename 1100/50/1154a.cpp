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

template <typename T, size_t N>
void answer(const std::array<T, N>& v)
{
    if constexpr (N > 0) {
        for (size_t i = 0; i < N - 1; ++i)
            std::cout << v[i] << ' ';

        std::cout << v.back();
    }
    std::cout << '\n';
}

void solve(std::array<unsigned, 4>& x)
{
    std::sort(x.begin(), x.end());

    std::array<unsigned, 3> y;
    for (size_t i = 0; i < 3; ++i)
        y[i] = x.back() - x[i];

    answer(y);
}

int main()
{
    std::array<unsigned, 4> x;
    std::cin >> x;

    solve(x);

    return 0;
}

