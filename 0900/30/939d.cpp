#include <iostream>
#include <string>
#include <utility>
#include <vector>

class DisjointSetUnion {
public:
    explicit DisjointSetUnion(unsigned size)
        : size_(size)
        , data_(size, -1)
    {}

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

void answer(const std::vector<std::pair<char, char>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<char, char>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();

    std::vector<std::pair<char, char>> p;
    {
        DisjointSetUnion dsu(26);
        for (size_t i = 0; i < n; ++i) {
            if (s[i] != t[i] && dsu.unite(s[i] - 'a', t[i] - 'a'))
                p.emplace_back(s[i], t[i]);
        }
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
