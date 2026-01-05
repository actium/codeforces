#include <iostream>
#include <set>
#include <utility>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

class DisjointSetUnion {
public:
    explicit DisjointSetUnion(unsigned size)
        : size_(size)
        , data_(size, -1)
    {}

    unsigned size(unsigned x) noexcept
    {
        return -data_[locate(x)];
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

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& e)
{
    DisjointSetUnion dsu(n);

    std::multiset<unsigned> s;
    for (size_t i = 0; i < n; ++i)
        s.insert(1);

    const auto count = [&](unsigned x) {
        unsigned k = 0;
        for (auto it = s.rbegin(); it != s.rend() && x-- != 0; ++it)
            k += *it;

        return k;
    };

    unsigned x = 1;
    for (const std::pair<unsigned, unsigned>& q : e) {
        if (dsu.locate(q.first - 1) != dsu.locate(q.second - 1)) {
            s.erase(s.find(dsu.size(q.first - 1)));
            s.erase(s.find(dsu.size(q.second - 1)));
            dsu.unite(q.first - 1, q.second - 1);
            s.insert(dsu.size(q.first - 1));
        } else {
            ++x;
        }

        answer(count(x) - 1);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, d;
    std::cin >> n >> d;

    std::vector<std::pair<unsigned, unsigned>> e(d);
    std::cin >> e;

    solve(n, e);

    return 0;
}
