#include <functional>
#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<unsigned>& x)
{
    const size_t n = a.size();

    std::map<unsigned, std::vector<size_t>> q;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] < b[i])
            return answer(false);

        if (a[i] > b[i])
            q[b[i]].push_back(i);
    }

    std::map<unsigned, unsigned> r;
    for (const unsigned v : x)
        ++r[v];

    const RangeQueryTable<unsigned> rqt(b.begin(), b.end(), [](unsigned u, unsigned v) { return std::max(u, v); });
    for (auto it = q.rbegin(); it != q.rend(); ++it) {
        unsigned c = 1;
        for (size_t i = 1; i < it->second.size(); ++i) {
            if (rqt.query<false>(it->second[i-1], it->second[i]) > it->first)
                ++c;
        }

        const auto jt = r.find(it->first);
        if (jt == r.end() || jt->second < c)
            return answer(false);

        jt->second -= c;
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> x(m);
    std::cin >> x;

    solve(a, b, x);
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
