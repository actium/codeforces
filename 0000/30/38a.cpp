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

void solve(const std::vector<size_t>& d, unsigned a, unsigned b)
{
    size_t c = 0;
    for (unsigned i = a; i < b; ++i)
        c += d[i-1];

    answer(c);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> d(n-1);
    std::cin >> d;

    unsigned a, b;
    std::cin >> a >> b;

    solve(d, a, b);

    return 0;
}

