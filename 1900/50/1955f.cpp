#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::array<unsigned, 4>& p)
{
    unsigned k = 0;
    for (size_t i = 0; i < 4; ++i) {
        k += p[i] / 2;
        p[i] %= 2;
    }

    answer(k + (p[0] * p[1] * p[2]));
}

void test_case()
{
    std::array<unsigned, 4> p;
    std::cin >> p;

    solve(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
