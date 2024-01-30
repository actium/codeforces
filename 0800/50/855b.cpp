#include <functional>
#include <iostream>
#include <limits>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(int p, int q, int r, const std::vector<int>& a)
{
    const size_t n = a.size();

    const RangeQueryTable<int> min_rqt(a.begin(), a.end(), [](int x, int y) { return std::min(x, y); });
    const RangeQueryTable<int> max_rqt(a.begin(), a.end(), [](int x, int y) { return std::max(x, y); });

    integer v = std::numeric_limits<integer>::min();
    for (size_t j = 0; j < n; ++j) {
        const integer lx = min_rqt.query<false>(0, j + 1);
        const integer ux = max_rqt.query<false>(0, j + 1);
        const integer ly = min_rqt.query<false>(j, n);
        const integer uy = max_rqt.query<false>(j, n);
        v = std::max(v, std::max(lx * p, ux * p) + integer(a[j]) * q + std::max(ly * r, uy * r));
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    int p, q, r;
    std::cin >> p >> q >> r;

    std::vector<int> a(n);
    std::cin >> a;

    solve(p, q, r, a);

    return 0;
}
