#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned v)
{
    const size_t n = a.size();

    double x = v;
    for (size_t i = 0; i < n; ++i)
        x = std::min(x, 1.0 * b[i] / a[i]);

    double u = 0;
    for (const unsigned q : a)
        u += x * q;

    answer(std::min<double>(u, v));
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned v;
    std::cin >> v;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, v);

    return 0;
}
