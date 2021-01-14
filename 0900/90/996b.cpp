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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> b(n);
    for (size_t i = 0; i < n; ++i) {
        const unsigned k = a[i] / n, r = a[i] % n;
        b[i] = k * n + i;
        if (b[i] < a[i])
            b[i] += n;
    }

    size_t x = 0;
    for (size_t i = 1; i < n; ++i) {
        if (b[i] < b[x])
            x = i;
    }

    answer(x);
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

