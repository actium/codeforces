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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t m = a.size();

    std::vector<unsigned> pa(1+m), pb(1+m);
    for (size_t i = 0; i < m; ++i) {
        pa[i+1] = pa[i] + a[i];
        pb[i+1] = pb[i] + b[i];
    }

    unsigned x = std::max(pa[m], pb[m]);
    for (size_t i = 0; i < m; ++i) {
        const unsigned y = std::max(pa[m] - pa[i+1], pb[i]);
        x = std::min(x, y);
    }

    answer(x);
}

void test_case()
{
    size_t m;
    std::cin >> m;

    std::vector<unsigned> a(m), b(m);
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
