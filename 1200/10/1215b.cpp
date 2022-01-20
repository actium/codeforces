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

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    integer s = 1, q = 1;
    for (size_t i = 0; i < n; ++i) {
        s ^= (a[i] < 0);
        q += s;
    }

    const integer k = q * (1 + n - q);
    answer(k, n * (n + 1ull) / 2 - k);
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
