#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, const std::vector<unsigned>& x)
{
    const size_t k = x.size();

    unsigned t = std::max(x.front(), 1 + n - x.back());
    for (size_t i = 1; i < k; ++i)
        t = std::max(t, 1 + (x[i] - x[i-1]) / 2);

    answer(t);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> x(k);
    std::cin >> x;

    solve(n, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

