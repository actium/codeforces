#include <array>
#include <iostream>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, const std::array<size_t, 7>& a)
{
    size_t i = 0;
    for (int remaining = n; remaining > 0; ) {
        remaining -= a[i];
        i = (i + 1) % 7;
    }

    answer(i == 0 ? 7 : i);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::array<size_t, 7> a;
    std::cin >> a;

    solve(n, a);

    return 0;
}

