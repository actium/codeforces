#include <algorithm>
#include <iostream>
#include <map>
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

std::pair<unsigned, unsigned> compress(std::vector<unsigned>& a)
{
    const auto end = std::unique(a.begin(), a.end());

    std::map<unsigned, unsigned> x;
    for (auto it = a.begin(); it != end; ++it) {
        const auto jt = x.emplace(*it, x.size()).first;
        *it = jt->second;
    }

    return std::make_pair(end - a.begin(), x.size());
}

void solve(std::vector<unsigned>& a, unsigned k, unsigned t)
{
    const auto [n, m] = compress(a);
    if (t >= m)
        return answer(1);

    std::vector<unsigned> d(n);
    {
        std::vector<unsigned> f(m);
        for (unsigned i = 0, j = 0, c = 0; i < n; ++i) {
            while (c <= t) {
                c += (++f[a[j % n]] == 1);
                ++j;
            }

            d[i] = (j - 1) - i;

            c -= (--f[a[i]] == 0);
        }
    }

    integer q = 0;
    {
        std::vector<std::pair<unsigned, unsigned>> v(n, { ~0u, ~0u });
        for (unsigned b = 0, c = 0; b < k; ) {
            if (v[c].first != ~0u) {
                const integer d = integer(b - v[c].first) * n, r = integer(k - b) * n - c, u = r / d;
                b += u * (b - v[c].first);
                q += u * (q - v[c].second);
                v[c].first = ~0u;
            } else {
                v[c] = { b, q++ };
                c += d[c];
                if (c >= n) {
                    c -= n;
                    ++b;
                }
            }
        }
    }
    return answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, k, t;
    std::cin >> n >> k >> t;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k, t);

    return 0;
}
