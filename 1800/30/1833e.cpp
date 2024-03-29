#include <algorithm>
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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

class DisjointSetUnion {
public:
    explicit DisjointSetUnion(unsigned size)
        : size_(size)
        , data_(size, -1)
    {}

    unsigned size() const noexcept
    {
        return size_;
    }

    unsigned locate(unsigned x) noexcept
    {
        unsigned rx = x;
        while (data_[rx] >= 0)
            rx = data_[rx];

        while (data_[x] >= 0)
            x = std::exchange(data_[x], rx);

        return rx;
    }

    bool unite(unsigned u, unsigned v)
    {
        unsigned ru = locate(u), rv = locate(v);
        if (ru == rv)
            return false;

        if (data_[ru] > data_[rv])
            std::swap(ru, rv);

        data_[ru] += data_[rv];
        data_[rv] = ru;
        --size_;

        return true;
    }

private:
    unsigned size_;

    std::vector<int> data_;

}; // class DisjointSetUnion

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    DisjointSetUnion dsu(n);
    for (size_t i = 0; i < n; ++i)
        dsu.unite(i, a[i]-1);

    const unsigned k = dsu.size();

    std::map<size_t, std::vector<unsigned>> s;
    for (size_t i = 0; i < n; ++i)
        s[dsu.locate(i)].push_back(a[i]);

    unsigned q = k;
    for (auto& e : s) {
        std::sort(e.second.begin(), e.second.end());
        if (e.second.size() == 2 || std::unique(e.second.begin(), e.second.end()) != e.second.end())
            --q;
    }

    answer(std::min(q + 1, k), k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
