#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

int f(unsigned c1, unsigned c2, unsigned a, unsigned b)
{
    if (c1 < 2 && c2 < 2)
        return c1 == c2 ? 0 : -1;

    if (c1 == 2 && c2 == 2)
        return 2 * std::min(a, b);

    if (c1 == 2)
        return c2 == 0 ? a : b;

    return c1 == 0 ? a : b;
}

void solve(const std::vector<unsigned>& c, unsigned a, unsigned b)
{
    const size_t n = c.size();

    unsigned s = 0;
    for (size_t i = 0; i < n/2; ++i) {
        const int d = f(c[i], c[n-1-i], a, b);
        if (d == -1)
            return answer(-1);

        s += d;
    }

    if (n % 2 == 1 && c[n/2] == 2)
        s += std::min(a, b);

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c, a, b);

    return 0;
}

