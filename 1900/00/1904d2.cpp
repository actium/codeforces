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
    explicit RangeQueryTable(Iterator lb, Iterator ub, F&& combine)
        : combine_(combine)
    {
        const unsigned n = ub - lb;

        data_.reserve(w - __builtin_clz(n) + 1);
        data_.emplace_back(lb, ub);
        for (unsigned i = 1; (1 << i) <= n; ++i) {
            const unsigned k = n - (1 << i) + 1;

            data_.emplace_back(k);
            for (unsigned j = 0; j < k; ++j)
                data_[i][j] = combine_(data_[i-1][j], data_[i-1][j+(1 << i - 1)]);
        }
    }

    template <bool cascading>
    T query(unsigned lb, unsigned ub) const
    {
        unsigned x = w - __builtin_clz(ub - lb);

        T value = data_[x][lb];
        if constexpr (!cascading) {
            value = combine_(value, data_[x][ub - (1 << x)]);
        } else {
            for (lb += 1 << x; lb < ub; lb += 1 << x) {
                x = w - __builtin_clz(ub - lb);
                value = combine_(value, data_[x][lb]);
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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    const RangeQueryTable<unsigned> ta(a.begin(), a.end(), [](unsigned a, unsigned b) { return std::max(a, b); });
    const RangeQueryTable<unsigned> tb(b.begin(), b.end(), [](unsigned a, unsigned b) { return std::min(a, b); });

    const auto search_l = [&](size_t x) {
        if (x == 0 || ta.query<false>(0, x) < b[x])
            return false;

        size_t lb = 0, ub = x;
        while (lb + 1 < ub) {
            const size_t mid = (lb + ub) / 2;
            (ta.query<false>(mid, x) >= b[x] ? lb : ub) = mid;
        }

        return a[lb] == b[x] && tb.query<false>(lb, x) >= a[lb];
    };

    const auto search_r = [&](size_t x) {
        if (ta.query<false>(x, n) < b[x])
            return false;

        size_t lb = x, ub = n;
        while (lb + 1 < ub) {
            const size_t mid = (lb + ub) / 2;
            (ta.query<false>(x, mid) < b[x] ? lb : ub) = mid;
        }

        return a[lb] == b[x] && tb.query<false>(x, lb) >= a[lb];
    };

    for (size_t i = 0; i < n; ++i) {
        if (a[i] == b[i])
            continue;

        if (a[i] > b[i] || !search_l(i) && !search_r(i))
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
