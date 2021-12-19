#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    unsigned f[2] = {};
    for (const unsigned x : a) {
        if (x < 2)
            ++f[x];
    }

    answer(f[1] * (1ull << f[0]));
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
