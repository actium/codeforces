#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct ItemSet {
    unsigned w;
    std::vector<unsigned> v;
};

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(ItemSet& a, ItemSet& b, unsigned s)
{
    std::sort(a.v.begin(), a.v.end(), std::greater<unsigned>());
    std::sort(b.v.begin(), b.v.end(), std::greater<unsigned>());

    a.v.resize(s / a.w);
    b.v.resize(s / b.w);

    const size_t n = a.v.size(), m = b.v.size();

    integer w = 0, v = 0;
    for (size_t i = 0; i < n; ++i) {
        w += a.w;
        v += a.v[i];
    }

    integer u = (w <= s ? v : 0);
    for (size_t i = n, j = 0; j < m; ++j) {
        w += b.w;
        v += b.v[j];

        while (i > 0 && w > s) {
            w -= a.w;
            v -= a.v[--i];
        }

        if (w <= s && v > u)
            u = v;
    }

    answer(u);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned s;
    std::cin >> s;

    ItemSet a, b;
    std::cin >> a.w >> b.w;

    a.v.resize(n);
    std::cin >> a.v;

    b.v.resize(m);
    std::cin >> b.v;

    solve(a, b, s);

    return 0;
}

