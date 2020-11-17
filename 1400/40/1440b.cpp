#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t k, const std::vector<unsigned>& a)
{
    const size_t m = n - (n - 1) / 2;

    unsigned long long s = 0;
    for (size_t i = 0, j = a.size(); i < k; ++i, j -= m)
        s += a[j - m];

    answer(s);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n * k);
    std::cin >> a;

    solve(n, k, a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

