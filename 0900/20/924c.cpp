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

void solve(const std::vector<unsigned>& m)
{
    const size_t n = m.size();

    size_t x = 0;
    for (size_t i = 1; i < n; ++i) {
        if (m[i] > m[x])
            x = i;
    }

    std::vector<unsigned> b = m;
    for (size_t i = 1; i < x; ++i)
        b[i] = std::max(b[i], b[i-1]);
    for (size_t i = x; i < n; ++i)
        b[i] = m[x];

    for (size_t i = x; i > 0; --i) {
        if (b[i-1] + 1 < b[i])
            b[i-1] = b[i] - 1;
    }

    integer k = 0;
    for (size_t i = 0; i < n; ++i)
        k += b[i] - m[i];

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> m(n);
    std::cin >> m;

    solve(m);

    return 0;
}
