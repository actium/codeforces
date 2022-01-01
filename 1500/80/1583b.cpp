#include <iostream>
#include <vector>

struct Restriction {
    unsigned a;
    unsigned b;
    unsigned c;
};

std::istream& operator >>(std::istream& input, Restriction& v)
{
    return input >> v.a >> v.b >> v.c;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void solve(size_t n, const std::vector<Restriction>& r)
{
    std::vector<bool> v(n);
    for (const auto& q : r)
        v[q.b-1] = true;

    size_t x = 0;
    while (x < n && v[x])
        ++x;

    std::vector<std::pair<size_t, size_t>> e;
    for (size_t i = 0; i < n; ++i) {
        if (i != x)
            e.emplace_back(i, x);
    }

    answer(e);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<Restriction> r(m);
    std::cin >> r;

    solve(n, r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
