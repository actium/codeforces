#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    for (const integer x : v)
        std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& c, const std::vector<std::pair<unsigned, unsigned>>& q)
{
    const size_t n = a.size(), m = q.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) {
        return c[i] != c[j] ? c[i] < c[j] : i < j;
    });

    std::vector<integer> v(m);
    for (size_t i = 0, x = 0; i < m; ++i) {
        auto [t, d] = q[i];

        integer k = std::min(a[t-1], d);
        v[i] += k * c[t-1];
        a[t-1] -= k;
        d -= k;

        while (d != 0 && x < n) {
            k = std::min(a[p[x]], d);
            v[i] += k * c[p[x]];
            a[p[x]] -= k;
            d -= k;
            x += (a[p[x]] == 0);
        }

        if (d != 0) {
            v[i] = 0;
            break;
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), c(n);
    std::cin >> a >> c;

    std::vector<std::pair<unsigned, unsigned>> q(m);
    std::cin >> q;

    solve(a, c, q);

    return 0;
}
