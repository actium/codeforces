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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, unsigned c)
{
    const size_t n = a.size();

    for (size_t i = 0; i < n; ++i)
        a[i] += i + 1;

    std::sort(a.begin(), a.end());

    unsigned k = 0;
    for (size_t i = 0; i < n && a[i] <= c; ++i) {
        c -= a[i];
        ++k;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned c;
    std::cin >> c;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
