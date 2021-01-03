#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::vector<bool> p(n);
    for (size_t i = 1; i < n-1; ++i)
        p[i] = (a[i-1] < a[i] && a[i] > a[i+1]);

    unsigned x = 1, b = 1;
    for (size_t i = 1; i < k-1; ++i)
        b += p[i];

    size_t c = b;
    for (size_t i = k; i < n; ++i) {
        c += p[i-1] - p[i-k+1];

        if (c > b) {
            b = c;
            x = 1 + i - k + 1;
        }
    }

    answer(b, x);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

