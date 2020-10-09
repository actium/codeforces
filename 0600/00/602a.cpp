#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(char v)
{
    std::cout << v << '\n';
}

integer convert(const std::vector<unsigned>& x, unsigned b)
{
    integer y = 0;
    for (const unsigned d : x) {
        y *= b;
        y += d;
    }
    return y;
}

void solve(const std::vector<unsigned>& x, unsigned bx, const std::vector<unsigned>& y, unsigned by)
{
    const integer u = convert(x, bx);
    const integer v = convert(y, by);

    if (u == v)
        return answer('=');

    answer(u < v ? '<' : '>');
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned bx;
    std::cin >> bx;

    std::vector<unsigned> x(n);
    std::cin >> x;

    size_t m;
    std::cin >> m;

    unsigned by;
    std::cin >> by;

    std::vector<unsigned> y(m);
    std::cin >> y;

    solve(x, bx, y, by);

    return 0;
}

