#include <algorithm>
#include <iostream>
#include <vector>

using vector_t = std::vector<unsigned>;

using integer = unsigned long long;

constexpr integer oo = ~integer(0);

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

void solve(unsigned n, unsigned s, const vector_t& a, const vector_t& b, const vector_t& c, const vector_t& d)
{
    const size_t m = a.size();

    integer t = oo;
    for (size_t i = 0; i < m; ++i) {
        if (b[i] > s)
            continue;

        const size_t x = std::upper_bound(d.begin(), d.end(), s - b[i]) - d.begin();

        const integer k = n - (x == 0 ? 0 : std::min(n, c[x-1]));
        t = std::min(t, k * a[i]);
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    size_t m, k;
    std::cin >> m >> k;

    unsigned x, s;
    std::cin >> x >> s;

    vector_t a(m), b(m);
    std::cin >> a >> b;

    vector_t c(k), d(k);
    std::cin >> c >> d;

    a.push_back(x);
    b.push_back(0);

    solve(n, s, a, b, c, d);

    return 0;
}
