#include <algorithm>
#include <iostream>
#include <map>
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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<int> b = a;
    std::sort(b.begin(), b.end());

    std::map<int, unsigned> x;
    for (size_t i = 0; i < n; ++i)
        x.emplace(b[i], x.size());

    for (size_t i = 0; i < n; ++i)
        b[i] = x[a[i]];

    integer k = 0;
    {
        const size_t m = x.rbegin()->second + 1;

        BinaryIndexedTree<unsigned> bit(m);
        for (size_t i = 0; i < n; ++i) {
            k += std::min(bit.sum(0, b[i]), bit.sum(b[i]+1, m));
            bit.update(b[i], 1);
        }
    }
    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);
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
