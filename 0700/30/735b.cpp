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

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(std::vector<unsigned>& a, size_t n1, size_t n2)
{
    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    if (n1 > n2)
        std::swap(n1, n2);

    unsigned long long m1 = 0;
    for (size_t i = 0; i < n1; ++i)
        m1 += a[i];

    unsigned long long m2 = 0;
    for (size_t i = 0; i < n2; ++i)
        m2 += a[n1 + i];

    answer(double(m1) / n1 + double(m2) / n2);
}

int main()
{
    size_t n, n1, n2;
    std::cin >> n >> n1 >> n2;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, n1, n2);

    return 0;
}

