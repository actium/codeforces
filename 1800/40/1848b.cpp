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

struct X {
    int z = -1;

    unsigned d1 = 0;
    unsigned d2 = 0;

    void update(size_t i)
    {
        unsigned d = i - z - 1;
        if (d > d2)
            std::swap(d2, d);
        if (d > d1)
            std::swap(d1, d);

        z = i;
    }
};

void solve(const std::vector<unsigned>& c, size_t k)
{
    const size_t n = c.size();

    std::vector<X> xs(k);
    for (size_t i = 0; i < n; ++i) {
        xs[c[i] - 1].update(i);
    }

    unsigned d = n;
    for (size_t i = 0; i < k; ++i) {
        xs[i].update(n);

        d = std::min(d, std::max(xs[i].d1, xs[i].d2 / 2));
    }

    answer(d);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
