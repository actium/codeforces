#include <iostream>
#include <vector>

size_t lsb(size_t x)
{
    return x & -x;
}

class Counter {
public:
    explicit Counter(size_t size)
        : v_(size)
        , s_(1 + size)
    {}

    void increment(size_t index)
    {
        if (v_[index]++ == 0)
            update(index, 1);
    }

    void decrement(size_t index)
    {
        if (--v_[index] == 0)
            update(index, -1);
    }

    bool check(size_t lb, size_t ub) const
    {
        return sum(lb, ub) == ub - lb;
    }

private:
    void update(size_t index, int delta)
    {
        for (size_t i = 1 + index; i < s_.size(); i += lsb(i))
            s_[i] += delta;
    }

    unsigned sum(size_t lb, size_t ub) const
    {
        unsigned s = 0;
        for (size_t i = ub; i > 0; i &= ~lsb(i))
            s += s_[i];

        for (size_t i = lb; i > 0; i &= ~lsb(i))
            s -= s_[i];

        return s;
    }

private:
    std::vector<unsigned> v_;
    std::vector<unsigned> s_;

}; // class Counter

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, q;
    std::cin >> n >> q;

    Counter rc(n), cc(n);
    while (q-- > 0) {
        unsigned t;
        std::cin >> t;

        if (t == 1) {
            unsigned r, c;
            std::cin >> r >> c;

            rc.increment(r-1);
            cc.increment(c-1);
        }
        if (t == 2) {
            unsigned r, c;
            std::cin >> r >> c;

            rc.decrement(r-1);
            cc.decrement(c-1);
        }
        if (t == 3) {
            unsigned r1, c1, r2, c2;
            std::cin >> r1 >> c1 >> r2 >> c2;

            std::cout << (rc.check(r1-1, r2) || cc.check(c1-1, c2) ? "Yes" : "No") << '\n';
        }
    }

    return 0;
}
