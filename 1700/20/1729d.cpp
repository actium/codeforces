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

void solve(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    const size_t n = x.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) { return x[i] + y[j] < x[j] + y[i]; });

    unsigned k = 0;
    for (int i = 0, j = n-1; i < j; ++i, --j) {
        while (j > i && y[p[i]] + y[p[j]] < x[p[i]] + x[p[j]])
            --j;
        
        k += (j > i);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n), y(n);
    std::cin >> x >> y;

    solve(x, y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
