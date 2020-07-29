#include <iostream>
#include <numeric>
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

void solve(const std::vector<unsigned>& x)
{
    const size_t n = x.size();

    unsigned a = x[0];
    for (size_t i = 1; i < n; ++i)
        a = std::gcd(a, x[i]);

    answer(a * n);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x);

    return 0;
}

