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
    unsigned t;
    union {
        struct {
            unsigned l;
            unsigned r;
        };
        unsigned x;
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    std::cin >> q.t;
    return q.t == 1 ? input >> q.l >> q.r : input >> q.x;
}

void answer(const std::vector<unsigned>& v)
{
    for (const unsigned x : v)
        std::cout << x << '\n';
}

class BinaryIndexedTree {
public:
    explicit BinaryIndexedTree(unsigned size)
        : data_(1 + size)
    {}

    void update(unsigned index, int delta)
    {
        const unsigned n = data_.size();

        for (unsigned i = 1 + index; i < n; i += i & -i)
            data_[i] += delta;
    }

    unsigned prefix_sum(unsigned range_end) const
    {
        unsigned sum = 0;
        for (unsigned i = 1 + range_end; i > 0; i &= ~(i & -i))
            sum += data_[i];

        return sum;
    }

private:
    std::vector<unsigned> data_;

}; // class BinaryIndexedTree

unsigned sum_digits(unsigned x)
{
    unsigned s = 0;
    while (x != 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

void solve(std::vector<unsigned>& a, const std::vector<Query>& r)
{
    std::vector<unsigned> v;

    BinaryIndexedTree bit(a.size());
    for (const Query& q : r) {
        if (q.t == 1) {
            bit.update(q.l - 1, 1);
            bit.update(q.r, -1);
            continue;
        }
        if (a[q.x-1] > 9) {
            const unsigned k = bit.prefix_sum(q.x - 1);
            for (unsigned i = 0; i < k && a[q.x-1] > 9; ++i)
                a[q.x-1] = sum_digits(a[q.x-1]);

            bit.update(q.x-1, -k);
            bit.update(q.x, k);
        }
        v.push_back(a[q.x-1]);
    }

    answer(v);
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<Query> r(q);
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
