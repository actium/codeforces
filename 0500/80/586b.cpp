#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a, const std::vector<unsigned>& b)
{
    const size_t n = b.size();

    const auto t = [&](size_t x) {
        unsigned c = b[x];

        for (size_t i = 0; i < x; ++i)
            c += a[0][i];

        for (size_t i = x; i < n-1; ++i)
            c += a[1][i];

        return c;
    };

    unsigned k = ~0u;
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j)
            k = std::min(k, t(i) + t(j));
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(2, std::vector<unsigned>(n-1));
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b);

    return 0;
}

