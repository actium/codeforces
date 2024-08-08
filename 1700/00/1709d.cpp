#include <functional>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    unsigned rs;
    unsigned cs;
    unsigned rt;
    unsigned ct;
    unsigned k;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.rs >> q.cs >> q.rt >> q.ct >> q.k;
}

template <typename T, typename F = std::function<T(T, T)>>
class RangeQueryTable {
public:
    template <typename Iterator>
    RangeQueryTable(Iterator begin, Iterator end, F&& combine)
        : combine_(combine)
    {
        const unsigned n = end - begin;

        data_.reserve(w - __builtin_clz(n) + 1);
        data_.emplace_back(begin, end);
        for (unsigned i = 1; (1 << i) <= n; ++i) {
            const unsigned k = n - (1 << i) + 1;

            data_.emplace_back(k);
            for (unsigned j = 0; j < k; ++j)
                data_[i][j] = combine_(data_[i-1][j], data_[i-1][j+(1 << i - 1)]);
        }
    }

    template <bool cascading>
    T query(unsigned range_begin, unsigned range_end) const
    {
        unsigned x = w - __builtin_clz(range_end - range_begin);

        T value = data_[x][range_begin];
        if constexpr (!cascading) {
            value = combine_(value, data_[x][range_end - (1 << x)]);
        } else {
            for (range_begin += 1 << x; range_begin < range_end; range_begin += 1 << x) {
                x = w - __builtin_clz(range_end - range_begin);
                value = combine_(value, data_[x][range_begin]);
            }
        }
        return value;
    }

private:
    const F combine_;

    std::vector<std::vector<T>> data_;

    static constexpr unsigned w = __builtin_clz(1);

}; // class RangeQueryTable<T, F>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(size_t n, const std::vector<unsigned>& a, const std::vector<Query>& r)
{
    const RangeQueryTable<unsigned> rqt(a.begin(), a.end(), [](unsigned x, unsigned y) { return std::max(x, y); });

    for (const Query& q : r) {
        const unsigned lc = std::min(q.cs, q.ct), rc = std::max(q.cs, q.ct);
        const unsigned br = std::min(q.rs, q.rt), ur = std::max(q.rs, q.rt);

        unsigned h = std::max(rqt.query<false>(lc-1, rc) + 1, ur);
        if ((h - br) % q.k != 0)
            h += q.k - (h - br) % q.k;

        answer(h <= n && (h - ur) % q.k == 0 && (rc - lc) % q.k == 0);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(m);
    std::cin >> a;

    size_t q;
    std::cin >> q;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(n, a, r);

    return 0;
}
