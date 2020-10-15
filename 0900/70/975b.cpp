#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::array<unsigned, 14>& a)
{
    unsigned long long s = 0;
    for (size_t i = 0; i < 14; ++i) {
        unsigned long long k = 0;
        for (size_t j = 1; j <= 14; ++j) {
            const unsigned c = (j < 14 ? a[(i+j) % 14] : 0) + a[i] / 14 + (j <= a[i] % 14);
            if (c % 2 == 0)
                k += c;
        }

        s = std::max(s, k);
    }

    answer(s);
}

int main()
{
    std::array<unsigned, 14> a;
    std::cin >> a;

    solve(a);

    return 0;
}

