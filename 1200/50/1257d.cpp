#include <algorithm>
#include <iostream>
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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, std::vector<std::pair<unsigned, unsigned>>& h)
{
    const size_t n = a.size();

    std::sort(h.begin(), h.end());

    std::vector<std::pair<unsigned, unsigned>> f;
    for (auto it = h.rbegin(); it != h.rend(); ++it) {
        if (f.empty() || it->first != f.back().first && it->second > f.back().second)
            f.push_back(*it);
    }

    unsigned k = 0;
    for (size_t x = 0, p = 0; x < n; x = p) {
        unsigned ub = a[x];
        for (auto it = f.begin(); it != f.end() && it->first >= ub; ++it) {
            while (p < std::min(x + it->second, n) && it->first >= a[p])
                ub = std::max(ub, a[p++]);
        }

        if (p == x)
            return no_answer();

        ++k;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> h(m);
    std::cin >> h;

    solve(a, h);
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
