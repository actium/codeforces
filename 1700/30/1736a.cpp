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

    unsigned f = 0, g = 0, k = 0;
    for (size_t i = 0; i < n; ++i) {
        f += (a[i] == 0);
        g += (b[i] == 0);
        k += (a[i] != b[i]);
    }

    const unsigned d = std::abs(int(f - g));
    answer(d + (k > d));
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
