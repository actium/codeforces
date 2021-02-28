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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x, unsigned y, const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&a](size_t i, size_t j) { return a[i] < a[j]; });

    for (size_t i = 0; i < n; ++i) {
        const size_t j = p[i];

        const unsigned k = (b[j] + x - 1) / x;
        if (a[j] * (k - 1) >= y)
            return answer(false);

        if (a[j] * k >= y && i + 1 < n)
            return answer(false);

        y -= a[j] * k;
    }

    answer(true);
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(x, y, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

