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

void solve(const std::vector<unsigned>& a, size_t m, size_t k)
{
    const size_t n = a.size();

    size_t d = n;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 0 || a[i] > k)
            continue;

        if (i < m)
            d = m - i;
        else
            d = std::min(d, i - m);
    }

    answer(d * 10);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m-1, k);

    return 0;
}

