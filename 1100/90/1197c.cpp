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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<int> d(n-1);
    for (size_t i = 1; i < n; ++i)
        d[i-1] = a[i-1] - a[i];

    std::partial_sort(d.begin(), d.begin() + k, d.end());

    unsigned x = a.back() - a.front();
    for (size_t i = 1; i < k; ++i)
        x += d[i-1];

    answer(x);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
