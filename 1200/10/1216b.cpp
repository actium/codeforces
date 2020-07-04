#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t k, const std::vector<size_t>& v)
{
    std::cout << k << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> b(n);
    for (size_t i = 0; i < n; ++i)
        b[i] = i;

    std::sort(b.begin(), b.end(), [&a](size_t x, size_t y) { return a[x] > a[y]; });

    size_t k = 0;
    for (size_t i = 0; i < n; ++i)
        k += a[b[i]] * i + 1;

    answer(k, b);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

