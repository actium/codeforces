#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned u, const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << u << ' ' << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void make_ops(std::vector<unsigned>& a, size_t b, size_t e, std::vector<std::pair<size_t, size_t>>& s)
{
    const unsigned k = e - b;
    if (k == 0)
        return;

    for (unsigned i = 0; i < k; ++i) {
        if (a[b+i] == i)
            continue;

        s.emplace_back(b, b + i);

        for (unsigned j = 0; j <= i; ++j)
            a[b+j] = i;

        i = -1;
    }

    s.emplace_back(b, e - 1);
}

void solve(std::vector<unsigned>& a)
{
    const unsigned n = a.size(), m = 1 << n;

    std::pair<unsigned, unsigned> best = { 0, 0 };
    for (unsigned i = 0; i < m; ++i) {
        unsigned v = 0;
        for (unsigned x = m + i, p = 0; x != 0; x &= x - 1) {
            const unsigned j = __builtin_ctz(x), k = j - p;
            v += (j < n ? a[j] : 0) + k * k;
            p += k + 1;
        }

        best = std::max(best, std::make_pair(v, i));
    }

    std::vector<std::pair<size_t, size_t>> s;
    {
        for (unsigned x = m + best.second, p = 0; x != 0; x &= x - 1) {
            const unsigned j = __builtin_ctz(x), k = j - p;
            make_ops(a, p, j, s);
            p += k + 1;
        }
    }

    answer(best.first, s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
