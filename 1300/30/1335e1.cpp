#include <algorithm>
#include <iostream>
#include <vector>

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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> p[26];
    for (size_t i = 0; i < n; ++i)
        p[a[i]-1].push_back(i);

    const auto check = [&](size_t x, size_t k) {
        const size_t lb = p[x][k-1], ub = p[x][p[x].size()-k];

        size_t c = 0;
        for (size_t i = 0; i < 26; ++i) {
            const auto it = std::upper_bound(p[i].begin(), p[i].end(), lb);
            const auto jt = std::lower_bound(it, p[i].end(), ub);
            c = std::max<size_t>(c, jt - it);
        }
        return k + c + k;
    };

    size_t v = 0;
    for (size_t x = 0; x < 26; ++x) {
        v = std::max(v, p[x].size());

        for (size_t k = 1; 2 * k <= p[x].size(); ++k)
            v = std::max(v, check(x, k));
    }

    answer(v);
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
