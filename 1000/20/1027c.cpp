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
    std::cout << x << ' ' << x << ' ' << y << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : a)
        ++f[x];

    for (auto it = f.begin(); it != f.end(); ) {
        if (it->second >= 4)
            return answer(it->first, it->first);

        if (it->second < 2)
            it = f.erase(it);
        else
            ++it;
    }

    std::pair<unsigned, unsigned> s = { f.begin()->first, f.rbegin()->first };
    for (auto p = f.begin(), q = std::next(p); q != f.end(); ++p, ++q) {
        const auto u = 1ull * q->first * s.first, v = 1ull * p->first * s.second;
        if (u * u < v * v)
            s = std::make_pair(p->first, q->first);
    }

    answer(s.first, s.second);
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
