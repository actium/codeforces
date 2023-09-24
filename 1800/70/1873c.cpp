#include <array>
#include <iostream>

template <typename T, size_t n>
std::istream& operator >>(std::istream& input, std::array<T, n>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::array<std::string, 10>& a)
{
    const auto evaluate = [](size_t i, size_t j) {
        const size_t dr = (i < 5 ? i : 9 - i), dc = (j < 5 ? j : 9 - j);
        return std::min(dr, dc) + 1;
    };

    unsigned s = 0;
    for (size_t i = 0; i < 10; ++i) {
        for (size_t j = 0; j < 10; ++j) {
            if (a[i][j] == 'X')
                s += evaluate(i, j);
        }
    }

    answer(s);
}

void test_case()
{
    std::array<std::string, 10> a;
    std::cin >> a;

    solve(a);
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
