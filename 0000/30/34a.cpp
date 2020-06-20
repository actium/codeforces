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

size_t delta(unsigned x, unsigned y)
{
    return abs(int(x) - int(y));
}

void solve(const std::vector<unsigned>& h)
{
    const size_t n = h.size();

    size_t second = 0;
    for (size_t i = 1, min_delta = delta(h.back(), h.front()); i < n; ++i) {
        const size_t d = delta(h[i], h[i - 1]);
        if (d < min_delta) {
            min_delta = d;
            second = i;
        }
    }

    answer(second == 0 ? n : second, (second % n) + 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h);

    return 0;
}

