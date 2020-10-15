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

void solve(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    const size_t n = x.size();
    const size_t m = y.size();

    unsigned k = 0, px = 0, py = 0;
    for (size_t i = 0, j = 0; i < n || j < m; ) {
        if (px == 0 || px < py)
            px += x[i++];

        if (py == 0 || py < px)
            py += y[j++];

        if (px == py) {
            ++k;
            px = py = 0;
        }
    }

    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> x(n);
    std::cin >> x;

    std::vector<unsigned> y(m);
    std::cin >> y;

    solve(x, y);

    return 0;
}

