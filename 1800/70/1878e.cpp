#include <iostream>
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

template <typename T>
class RangeQueryTable {
public:
    template <typename Iterator, typename F>
    explicit RangeQueryTable(Iterator lb, Iterator ub, F&& combine)
    {
        const unsigned n = ub - lb;

        data_.emplace_back(lb, ub);
        for (unsigned i = 1; (1 << i) <= n; ++i) {
            const unsigned k = n - (1 << i) + 1;

            data_.emplace_back(k);
            for (unsigned j = 0; j < k; ++j)
                data_[i][j] = combine(data_[i-1][j], data_[i-1][j+(1 << i - 1)]);
        }
    }

    template <bool cascading, typename F>
    T query(unsigned lb, unsigned ub, F&& combine) const
    {
        unsigned x = w - __builtin_clz(ub - lb);

        T value = data_[x][lb];
        if constexpr (!cascading) {
            value = combine(value, data_[x][ub - (1 << x)]);
        } else {
            for (lb += 1 << x; lb < ub; lb += 1 << x) {
                x = w - __builtin_clz(ub - lb);
                value = combine(value, data_[x][lb]);
            }
        }
        return value;
    }

private:
    std::vector<std::vector<T>> data_;

    static constexpr unsigned w = __builtin_clz(1);

}; // class RangeQueryTable<T>

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size(), q = r.size();

    const auto combine = [](unsigned a, unsigned b) {
        return a & b;
    };

    const RangeQueryTable<unsigned> rqt(a.cbegin(), a.cend(), combine);

    std::vector<int> v(q, -1);
    for (size_t i = 0; i < q; ++i) {
        if (a[r[i].first-1] < r[i].second)
            continue;

        size_t lb = r[i].first - 1, ub = n + 1;
        while (lb + 1 < ub) {
            const size_t mid = (lb + ub) / 2;
            (rqt.query<false>(r[i].first - 1, mid, combine) >= r[i].second ? lb : ub) = mid;
        }

        v[i] = lb;
    }

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t q;
    std::cin >> q;

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
