#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

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

void no_answer()
{
    std::cout << -1 << '\n';
}

bool search(const std::vector<unsigned>& a, size_t x, size_t d, std::vector<unsigned>& c)
{
    const size_t n = a.size() / 2;

    if (a[x] == 0)
        c[x] = 0;

    if (c[x] == oo) {
        c[x] = oo >> 1;

        const size_t next = (n + x - d) % n;
        if (search(a, next, d, c))
            c[x] = c[next] + 1;
    }
    return c[x] != oo >> 1;
}

void solve(std::vector<unsigned>& a, size_t d)
{
    const size_t n = a.size();

    a.resize(2 * n);
    for (size_t i = 0; i < n; ++i)
        a[n+i] = a[i];

    std::vector<unsigned> c(n, oo);
    for (size_t i = 0; i < n; ++i) {
        if (!search(a, i, d, c))
            return no_answer();
    }

    unsigned x = 0;
    for (size_t i = 0; i < n; ++i)
        x = std::max(x, c[i]);

    answer(x);
}

void test_case()
{
    size_t n, d;
    std::cin >> n >> d;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, d);
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
