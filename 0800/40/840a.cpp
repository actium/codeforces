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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t m = a.size();

    std::vector<size_t> x(m), y(m);
    for (size_t i = 0; i < m; ++i) {
        x[i] = i;
        y[i] = i;
    }

    std::sort(x.begin(), x.end(), [&a](size_t i, size_t j) { return a[i] < a[j]; });
    std::sort(y.begin(), y.end(), [&b](size_t i, size_t j) { return b[i] > b[j]; });

    std::vector<unsigned> c(m);
    for (size_t i = 0; i < m; ++i)
        c[y[i]] = a[x[i]];

    answer(c);
}

int main()
{
    size_t m;
    std::cin >> m;

    std::vector<unsigned> a(m), b(m);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

