#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<size_t>& a, size_t d)
{
    const size_t n = a.size();

    size_t c = a[0];
    for (size_t i = 1; i < n; ++i) {
        const size_t k = std::min(a[i], d / i);
        c += k;
        d -= i * k;
    }

    answer(c);
}

void test_case()
{
    size_t n, d;
    std::cin >> n >> d;

    std::vector<size_t> a(n);
    std::cin >> a;

    solve(a, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

