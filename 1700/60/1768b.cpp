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

void solve(const std::vector<unsigned>& p, size_t k)
{
    const size_t n = p.size();

    unsigned x = 1;
    for (size_t i = 0; i < n; ++i) {
        if (p[i] == x)
            ++x;
    }

    answer((n - x + k) / k);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

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
