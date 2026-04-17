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
    const size_t n = a.size();

    unsigned k = (std::gcd(a[0], a[1]) < a[0]);
    for (size_t i = 1; i < n-1; ++i) {
        const unsigned p = std::gcd(a[i-1], a[i]);
        const unsigned q = std::gcd(a[i], a[i+1]);
        k += (std::lcm(p, q) < a[i]);
    }
    k += (std::gcd(a[n-2], a[n-1]) < a[n-1]);

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a);
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
