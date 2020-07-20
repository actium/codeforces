#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<size_t> b(n);
    std::iota(b.begin(), b.end(), 0);

    std::sort(b.begin(), b.end(), [&](size_t x, size_t y) { return a[x] < a[y]; });

    size_t i = 0;
    while (i < n && a[b[i]] <= k)
        k -= a[b[i++]];

    b.resize(i);
    answer(b);
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

