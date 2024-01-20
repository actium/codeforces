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

    const auto check = [&](size_t k) {
        unsigned d = 0;
        for (size_t i = 0; i < k; ++i) {
            for (size_t j = i; j < n; j += k)
                d = std::gcd(d, a[j] < a[i] ? a[i] - a[j] : a[j] - a[i]);
        }
        return d != 1;
    };

    unsigned q = 1;
    for (size_t i = 1; i < n; ++i) {
        if (n % i == 0)
            q += check(i);
    }

    answer(q);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
