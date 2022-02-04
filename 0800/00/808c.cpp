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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, int w)
{
    const size_t n = a.size();

    std::vector<unsigned> b(n);
    for (size_t i = 0; i < n; ++i) {
        b[i] = (a[i] + 1) / 2;
        w -= b[i];
    }

    if (w < 0)
        return no_answer();

    std::vector<size_t> o(n);
    for (size_t i = 0; i < n; ++i)
        o[i] = i;

    std::sort(o.begin(), o.end(), [&a](size_t x, size_t y) { return a[x] > a[y]; });

    for (const size_t i : o) {
        const unsigned c = std::min<unsigned>(a[i] - b[i], w);
        b[i] += c;
        w -= c;
    }

    answer(b);
}

int main()
{
    size_t n;
    std::cin >> n;

    int w;
    std::cin >> w;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, w);

    return 0;
}
