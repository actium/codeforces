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

unsigned optima(const std::vector<unsigned>& f, const std::vector<unsigned>& c)
{
    unsigned s = 0;
    for (const unsigned x : f)
        s += std::min(x * c[0], c[1]);

    return std::min(s, c[2]);
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<unsigned>& c)
{
    answer(std::min(optima(a, c) + optima(b, c), c[3]));
}

int main()
{
    std::vector<unsigned> c(4);
    std::cin >> c;

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(a, b, c);

    return 0;
}

