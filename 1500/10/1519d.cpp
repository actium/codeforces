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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    integer s = 0;
    for (size_t i = 0; i < n; ++i)
        s += 1ull * a[i] * b[i];

    integer v = s;
    for (size_t i = 0; i < n; ++i) {
        integer x1 = s;
        for (size_t k = 1; k <= i && i + k < n; ++k) {
            x1 -= 1ull * a[i-k] * b[i-k] + 1ull * a[i+k] * b[i+k];
            x1 += 1ull * a[i-k] * b[i+k] + 1ull * a[i+k] * b[i-k];
            v = std::max(v, x1);
        }

        integer x2 = s;
        for (size_t k = 0; k < i && i + k < n; ++k) {
            x2 -= 1ull * a[i-k-1] * b[i-k-1] + 1ull * a[i+k] * b[i+k];
            x2 += 1ull * a[i-k-1] * b[i+k] + 1ull * a[i+k] * b[i-k-1];
            v = std::max(v, x2);
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
