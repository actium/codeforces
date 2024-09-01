#include <algorithm>
#include <iostream>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
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

unsigned count(const std::vector<std::pair<unsigned, size_t>>& q)
{
    const size_t n = q.size();

    unsigned k = 0;
    {
        BinaryIndexedTree<unsigned> d(n);
        for (size_t i = n - 1; i > 0; --i) {
            const size_t p = q[i].second - d.sum(0, q[i].second);
            k ^= i - p;
            d.update(q[i].second, 1);
        }
    }
    return k % 2;
}

void solve(std::vector<std::pair<unsigned, size_t>>& a, std::vector<std::pair<unsigned, size_t>>& b)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    for (size_t i = 0; i < n; ++i) {
        if (a[i].first != b[i].first)
            return answer(false);
    }

    answer(count(a) == count(b));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, size_t>> a(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second = i;
    }

    std::vector<std::pair<unsigned, size_t>> b(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> b[i].first;
        b[i].second = i;
    }

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
