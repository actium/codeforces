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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned k)
{
    const size_t n = a.size(), m = b.size();

    const auto prepare = [](const std::vector<unsigned>& v) {
        std::vector<unsigned> c;
        {
            unsigned q = 0;
            for (const unsigned x : v) {
                if (x != 1 && q != 0) {
                    c.push_back(q);
                    q = 0;
                }
                q += x;
            }
            if (q != 0)
                c.push_back(q);
        }
        std::sort(c.begin(), c.end());
        return c;
    };

    const std::vector<unsigned> pa = prepare(a), pb = prepare(b);

    const auto count = [](const std::vector<unsigned>& p, unsigned d) {
        integer q = 0;
        for (auto it = std::lower_bound(p.begin(), p.end(), d); it != p.end(); ++it)
            q += *it - d + 1;

        return q;
    };

    integer q = 0;
    for (unsigned i = 1; i * i <= k; ++i) {
        if (k % i != 0)
            continue;

        q += count(pa, i) * count(pb, k / i);
        if (i * i != k)
            q += count(pa, k / i) * count(pb, i);
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b, k);

    return 0;
}
