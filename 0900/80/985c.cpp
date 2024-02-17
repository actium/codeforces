#include <algorithm>
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

void solve(std::vector<unsigned>& a, size_t k, unsigned l)
{
    const size_t m = a.size(), n = m / k;

    std::sort(a.begin(), a.end());

    const size_t x = std::upper_bound(a.begin(), a.end(), a[0] + l) - a.begin();
    if (x < n)
        return answer(0);

    integer v = 0;
    for (size_t i = 0, j = 0; i < n; ++i) {
        v += a[j];
        j += std::min(k, 1 + (x - j) - (n - i));
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    unsigned l;
    std::cin >> l;

    std::vector<unsigned> a(n * k);
    std::cin >> a;

    solve(a, k, l);

    return 0;
}
