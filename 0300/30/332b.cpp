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

void answer(size_t x, size_t y)
{
    std::cout << 1+x << ' ' << 1+y << '\n';
}

void solve(const std::vector<unsigned>& x, size_t k)
{
    using integer = unsigned long long;

    const size_t n = x.size();

    std::vector<integer> s(n + 1);
    for (size_t i = n; i > 0; --i) {
        s[i-1] = s[i] + x[i-1];
        if (i + k <= n)
            s[i-1] -= x[i+k-1];
    }

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    const RangeQueryTable<size_t> rqt(p.begin(), p.end(), [&](size_t i, size_t j) {
        return s[i] > s[j] || s[i] == s[j] && i < j ? i : j;
    });

    size_t a = 0, b = k;
    for (size_t i = 0; i + k < n; ++i) {
        const size_t u = i, v = rqt.query<false>(i + k, n);
        if (s[a] + s[b] < s[u] + s[v]) {
            a = u;
            b = v;
        }
    }

    answer(a, b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x, k);

    return 0;
}
