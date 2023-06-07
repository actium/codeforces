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
    const size_t n = a.size();

    unsigned k = 0;

    std::vector<unsigned> c(1 + 2 * n);
    for (size_t i = 0, j = 0; i < n; ++i) {
        if (a[i] != a[j])
            j = i;

        const unsigned q = i - j + 1;
        c[a[i]] = std::max(c[a[i]], q);

        k = std::max(k, q);
    }

    for (size_t i = 0, j = 0; i < n; ++i) {
        if (b[i] != b[j])
            j = i;

        const unsigned q = i - j + 1;
        k = std::max(k, c[b[i]] + q);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
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
