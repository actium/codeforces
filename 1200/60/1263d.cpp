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
    explicit ComponentSet(unsigned size)
        : size_(size)
        , roots_(size)
        , ranks_(size)
    {
        for (unsigned i = 0; i < size_; ++i)
            roots_[i] = i;
    }

    unsigned size() const
    {
        return size_;
    }

    void merge(unsigned u, unsigned v)
    {
        unsigned ru = resolve(u), rv = resolve(v);
        if (ru == rv)
            return;

        if (ranks_[ru] < ranks_[rv])
            std::swap(ru, rv);

        roots_[rv] = ru;

        if (ranks_[ru] == ranks_[rv])
            ++ranks_[ru];

        --size_;
    }

private:
    unsigned resolve(unsigned v)
    {
        while (v != roots_[v])
            v = std::exchange(roots_[v], roots_[roots_[v]]);

        return v;
    }

private:
    unsigned size_;

    std::vector<unsigned> roots_;
    std::vector<unsigned> ranks_;

}; // class ComponentSet

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size();

    std::vector<size_t> t[26];
    for (size_t i = 0; i < n; ++i) {
        for (const char c : s[i])
            t[c - 'a'].push_back(i);
    }

    ComponentSet cs(n);
    for (size_t i = 0; i < 26; ++i) {
        for (const size_t x : t[i])
            cs.merge(x, t[i][0]);
    }

    answer(cs.size());
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
