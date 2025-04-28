#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

template <typename T, typename F = std::function<T(T, T)>>
class RangeQueryTable {
public:
    template <typename Iterator>
    RangeQueryTable(Iterator begin, Iterator end, F&& combine)
        : combine_(std::forward<F>(combine))
    {
        const unsigned n = end - begin;

        data_.reserve(w - __builtin_clz(n) + 1);
        data_.emplace_back(begin, end);
        for (unsigned i = 1; (1 << i) <= n; ++i) {
            const unsigned k = n - (1 << i) + 1;

            data_.emplace_back(k);
            for (unsigned j = 0; j < k; ++j)
                data_[i][j] = combine_(data_[i-1][j], data_[i-1][j+(1 << i-1)]);
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

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size(), q = r.size();

    std::vector<unsigned> d(n);
    for (size_t i = 1; i < n; ++i)
        d[i-1] = std::max(a[i-1], a[i]) - std::min(a[i-1], a[i]);

    const RangeQueryTable<unsigned> rqt(d.begin(), d.end(), [](unsigned lhs, unsigned rhs) { return std::gcd(lhs, rhs); });

    std::vector<unsigned> v(q);
    for (size_t i = 0; i < q; ++i) {
        if (r[i].first != r[i].second)
            v[i] = rqt.query<false>(r[i].first-1, r[i].second-1);
    }

    answer(v);
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(a, r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
