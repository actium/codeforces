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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    int d = 0;
    for (size_t i = 1; i < n; ++i) {
        d = std::max<int>(d, a[i-1] - a[i]);
        d = std::max<int>(d, a[i] - a[0]);
        d = std::max<int>(d, a[n-1] - a[i-1]);
    }

    answer(d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
