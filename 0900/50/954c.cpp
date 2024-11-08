#include <iostream>
#include <vector>

constexpr unsigned oo = 1000000000;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << "YES" << '\n';
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned y = 1;
    for (size_t i = 1; i < n; ++i) {
        const unsigned d = std::max(a[i-1], a[i]) - std::min(a[i-1], a[i]);
        y = std::max(y, d);
    }

    for (size_t i = 1; i < n; ++i) {
        if (a[i] > a[i-1] && a[i-1] % y == 0 && a[i] % y != 0)
            return no_answer();

        if (a[i] < a[i-1] && a[i] % y == 0 && a[i-1] % y != 0)
            return no_answer();

        const unsigned d = std::max(a[i-1], a[i]) - std::min(a[i-1], a[i]);
        if (d != 1 && d != y)
            return no_answer();
    }

    answer(oo, y);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
