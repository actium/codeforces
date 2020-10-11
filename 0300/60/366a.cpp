#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << 1+x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned n, const std::array<std::array<unsigned, 4>, 4>& a)
{
    for (size_t i = 0; i < 4; ++i) {
        const unsigned x = std::min(a[i][0], a[i][1]);
        const unsigned y = std::min(a[i][2], a[i][3]);

        if (x + y <= n)
            return answer(i, x, n - x);
    }

    no_answer();
}

int main()
{
    unsigned n;
    std::cin >> n;

    std::array<std::array<unsigned, 4>, 4> a;
    std::cin >> a;

    solve(n, a);

    return 0;
}

