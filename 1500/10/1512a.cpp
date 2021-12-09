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

void answer(size_t x)
{
    std::cout << 1+x << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<size_t> p(101), f(101);
    for (size_t i = 0; i < n; ++i) {
        const int x = a[i];
        p[x] = i;
        ++f[x];
    }

    const auto it = std::find(f.begin(), f.end(), 1);
    answer(p[std::distance(f.begin(), it)]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
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
