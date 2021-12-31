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

void solve(const std::vector<unsigned>& a, integer h)
{
    const auto f = [&](integer k) {
        const size_t n = a.size();

        integer d = k;
        for (size_t i = 1; i < n; ++i)
            d += std::min<integer>(k, a[i] - a[i-1]);

        return d;
    };

    integer left = 0, right = h;
    while (left + 1 < right) {
        const integer mid = left + (right - left) / 2;
        if (f(mid) < h)
            left = mid;
        else
            right = mid;
    }

    answer(right);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer h;
    std::cin >> h;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, h);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

