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

void answer(unsigned x)
{
    std::cout << x << '\n'; 
}

void solve(const std::vector<unsigned>& a)
{
    unsigned x = 0;
    for (size_t i = 0, j = a.size() - 1; i < j; ++i, --j) {
        if (a[i] != a[j])
            x = std::gcd(x, std::max(a[i], a[j]) - std::min(a[i], a[j]));
    }

    answer(x);
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
