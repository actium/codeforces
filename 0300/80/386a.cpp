#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x, size_t y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<size_t>& p)
{
    const size_t n = p.size();

    size_t x = 0, y = 1;
    for (size_t i = 1; i < n; ++i) {
        if (p[i] > p[x]) {
            y = x;
            x = i;
        } else if (p[i] > p[y]) {
            y = i;
        }
    }

    answer(1 + x, p[y]);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}

