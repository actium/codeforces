#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    integer k = 0;
    {
        long long p = a[0], d = 0;
        for (size_t i = 1; i < n; ++i) {
            if (p > a[i] + d) {
                k += p - (a[i] + d);
            } else {
                k += (a[i] + d) - p;
                d += p - (a[i] + d);
            }

            p = a[i] + d;
        }

        k += std::abs(p);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
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
