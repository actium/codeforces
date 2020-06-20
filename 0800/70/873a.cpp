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

void solve(const std::vector<size_t>& a, size_t k, size_t x)
{
    const size_t n = a.size();
    if (k >= n)
        return answer(k * x);

    size_t s = 0;
    for (size_t i = 0; i < n - k; ++i)
        s += a[i];

    answer(s + k * x);
}

int main()
{
    size_t n, k, x;
    std::cin >> n >> k >> x;

    std::vector<size_t> a(n);
    std::cin >> a;

    solve(a, k, x);

    return 0;
}

