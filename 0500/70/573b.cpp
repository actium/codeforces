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

void solve(const std::vector<unsigned>& h)
{
    size_t n = h.size();

    std::vector<unsigned> c(n);
    c[0] = c[n-1] = 1;
    for (size_t i = 1; i + 1 < n; ++i)
        c[i] = std::min(c[i-1] + 1, h[i]);
    for (size_t i = n - 1; i > 0; --i)
        c[i-1] = std::min(c[i-1], c[i] + 1);

    unsigned k = 0;
    for (const unsigned x : c)
        k = std::max(k, x);

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h);

    return 0;
}
