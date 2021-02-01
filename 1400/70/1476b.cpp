#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& p, unsigned k)
{
    const size_t n = p.size();

    integer s = 0, d = 0;
    for (size_t i = 1; i < n; ++i) {
        s += p[i-1];

        if (100ull * p[i] > k * s + d)
            d = 100ull * p[i] - k * s;
    }

    answer((d + k - 1) / k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

