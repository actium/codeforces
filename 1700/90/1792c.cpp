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

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[p[i]-1] = i;

    size_t i = (n + 1) / 2, j = n / 2;
    while (i > 0 && (i == j + 1 || x[i-1] < x[i] && x[j-1] < x[j]))
        --i, ++j;

    answer((n - j + i + 1) / 2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);
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
