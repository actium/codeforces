#include <iostream>
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
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& x, const std::vector<unsigned>& y, size_t n)
{
    std::vector<size_t> z(n);

    for (const size_t a : x)
        z[a-1] = 1;

    for (const size_t b : y)
        z[b-1] = 2;

    answer(z);
}

int main()
{
    size_t n, a, b;
    std::cin >> n >> a >> b;

    std::vector<unsigned> x(a);
    std::cin >> x;

    std::vector<unsigned> y(b);
    std::cin >> y;

    solve(x, y, n);

    return 0;
}

