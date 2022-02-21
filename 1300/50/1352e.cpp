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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> ps(1+n), f(1+n);
    for (size_t i = 0; i < n; ++i) {
        ps[i+1] = ps[i] + a[i];
        ++f[a[i]];
    }

    unsigned k = 0;
    for (size_t i = 2; i <= n; ++i) {
        for (size_t j = 0; j < i - 1; ++j) {
            const unsigned d = ps[i] - ps[j];
            if (d <= n) {
                k += f[d];
                f[d] = 0;
            }
        }
    }

    answer(k);
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
