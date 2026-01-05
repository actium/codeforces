#include <iostream>
#include <utility>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

class ComponentSet {
public:
    explicit ComponentSet(size_t size) :
        size_(size), roots_(size), sizes_(size, 1)
    {
        for (size_t i = 0; i < size; ++i)
            roots_[i] = i;
    }

    size_t size() const noexcept
    {
        return size_;
    }

    size_t operator [](size_t x) noexcept
    {
        size_t root = x;
        while (root != roots_[root])
            root = roots_[root];

        while (roots_[x] != root)
            x = std::exchange(roots_[x], root);

        return root;
    }

    void merge(size_t x, size_t y) noexcept
    {
        size_t rx = operator [](x), ry = operator [](y);
        if (rx == ry)
            return;

        if (sizes_[rx] < sizes_[ry])
            std::swap(rx, ry);

        roots_[ry] = rx;
        sizes_[rx] += sizes_[ry];

        --size_;
    }

private:
    size_t size_;

    std::vector<size_t> roots_;
    std::vector<size_t> sizes_;

}; // class ComponentSet

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    ComponentSet cs(n);
    for (size_t i = 0; i < n; ++i)
        cs.merge(i, p[i] - 1);

    answer(cs.size());
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}

