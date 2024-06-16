#include <iostream>
#include <vector>

#include <cassert>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    unsigned r[2];
    unsigned c[2];
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.r[0] >> q.c[0] >> q.r[1] >> q.c[1];
};

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

template <typename T>
class PrefixSumArray {
public:
    template <typename F>
    PrefixSumArray(unsigned count, F&& generate)
        : data_(1 + count)
    {
        for (unsigned i = 0; i < count; ++i)
            data_[i+1] = data_[i] + generate(i);
    }

    T sum(unsigned begin, unsigned end) const
    {
        assert(begin <= end);
        assert(end < data_.size());
        return data_[end] - data_[begin];
    }

private:
    std::vector<T> data_;

}; // class PrefixSumArray<T>

void solve(const std::vector<unsigned>& r, const std::vector<unsigned>& c, const std::vector<Query>& q)
{
    const PrefixSumArray<unsigned> pr(r.size(), [&](size_t i) { return r[i] % 2; });
    const PrefixSumArray<unsigned> pc(c.size(), [&](size_t i) { return c[i] % 2; });

    const auto check = [&](unsigned sr, unsigned tr, unsigned sc, unsigned tc) {
        const unsigned u = pr.sum(sr, tr), v = pc.sum(sc, tc);
        return (u == 0 || u == tr - sr) && (v == 0 || v == tc - sc);
    };

    for (const Query& e : q) {
        const unsigned sr = std::min(e.r[0], e.r[1]) - 1, tr = std::max(e.r[0], e.r[1]);
        const unsigned sc = std::min(e.c[0], e.c[1]) - 1, tc = std::max(e.c[0], e.c[1]);

        answer(check(sr, tr, sc, tc));
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> r(n), c(n);
    std::cin >> r >> c;

    std::vector<Query> q(m);
    std::cin >> q;

    solve(r, c, q);

    return 0;
}
