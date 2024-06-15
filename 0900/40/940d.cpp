#include <functional>
#include <iostream>
#include <vector>

constexpr int oo = 1000000000;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x, int y)
{
    std::cout << x << ' ' << y << '\n';
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

void solve(const std::vector<int>& a, const std::string& b)
{
    const size_t n = a.size();

    const RangeQueryTable<int> min_t(a.begin(), a.end(), [](int u, int v) { return std::min(u, v); });
    const RangeQueryTable<int> max_t(a.begin(), a.end(), [](int u, int v) { return std::max(u, v); });

    int s = 0, lb = -oo, ub = oo;
    for (size_t i = 0; i < n; ++i) {
        if (i >= 4) {
            if (b[i] == '1' && s == 0)
                lb = std::max(lb, max_t.query<false>(i - 4, i + 1) + 1);

            if (b[i] == '0' && s == 4)
                ub = std::min(ub, min_t.query<false>(i - 4, i + 1) - 1);
        }

        s += b[i] - '0';

        if (i >= 4)
            s -= b[i-4] - '0';
    }

    answer(lb, ub);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    std::string b;
    std::cin >> b;

    solve(a, b);

    return 0;
}
