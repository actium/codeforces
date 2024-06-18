#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

template <typename T>
class BinaryIndexedTree {
public:
    explicit BinaryIndexedTree(unsigned size)
        : nodes_(1 + size)
    {}

    template <typename U>
    void update(unsigned index, U delta)
    {
        for (++index; index < nodes_.size(); index += index & -index)
            nodes_[index] += delta;
    }

    T sum(unsigned range_begin, unsigned range_end) const
    {
        auto sum = T();
        while (range_end > range_begin) {
            sum += nodes_[range_end];
            range_end &= range_end - 1;
        }
        while (range_begin > range_end) {
            sum -= nodes_[range_begin];
            range_begin &= range_begin - 1;
        }
        return sum;
    }

private:
    std::vector<T> nodes_;

}; // class BinaryIndexedTree<T>

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> p[100001];
    for (size_t i = 0; i < n; ++i)
        p[a[i]].push_back(i);

    integer q = 0;
    {
        BinaryIndexedTree<unsigned> d(n);
        for (size_t i = 1, x = 0; i <= 100000; ++i) {
            if (p[i].empty())
                continue;

            const size_t j = std::lower_bound(p[i].begin(), p[i].end(), x) - p[i].begin(), m = p[i].size();
            for (size_t k = 0; k < m; ++k) {
                const size_t y = p[i][(j+k)%m];
                if (x <= y)
                    q += 1 + (y - x - d.sum(x, y));
                else
                    q += 1 + (n - x - d.sum(x, n)) + (y - d.sum(0, y));

                d.update(y, 1);
                x = y;
            }
        }
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
