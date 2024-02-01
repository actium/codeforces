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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, unsigned x, unsigned y)
{
    std::sort(a.begin(), a.end());

    unsigned k = 0;
    for (const unsigned q : a) {
        unsigned dx = std::min(x, q / 2), dy = std::min(y, q - 2 * dx);
        if (dy == 0 && 2 * dx < q && dx < x)
            ++dx;

        if (2 * dx + dy >= q) {
            x -= dx;
            y -= dy;
            ++k;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned x, y;
    std::cin >> x >> y;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x, y);

    return 0;
}
