#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<size_t>& a)
{
    size_t f[2] = {};
    for (const size_t x : a)
        ++f[x - 1];

    const size_t k = std::min(f[0], f[1]);
    answer(k + (f[0] - k) / 3);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

