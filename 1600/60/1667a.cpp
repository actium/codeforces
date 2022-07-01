#include <iostream>
#include <vector>

using integer = long long;

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

    const auto count = [&a](size_t b, size_t e, int d) {
        integer k = 0, x = 0;
        for (size_t i = b; i != e; i += d) {
            x += a[i] - x % a[i];
            k += x / a[i];
        }
        return k;
    };

    integer k = ~0ull >> 1;
    for (size_t i = 0; i < n; ++i) {
        k = std::min(k, count(i - 1, -1, -1) + count(i + 1, n, 1));
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
