#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(std::array<int, 7>& a)
{
    int s = 0, x = a[0];
    for (const int v : a) {
        s += v;
        x = std::max(x, v);
    }

    answer(2 * x - s);
}

void test_case()
{
    std::array<int, 7> a;
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
