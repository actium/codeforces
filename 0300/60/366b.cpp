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
    std::cout << 1+v << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<unsigned> b(k);
    for (size_t i = 0; i < n; ++i)
        b[i % k] += a[i];

    size_t x = 0;
    for (size_t i = 1; i < k; ++i) {
        if (b[i] < b[x])
            x = i;
    }

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

