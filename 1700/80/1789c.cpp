#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const integer n = a.size(), m = r.size();

    std::vector<std::vector<std::pair<unsigned, unsigned>>> s(1 + n + m);
    for (const unsigned x : a)
        s[x].emplace_back(0, m);

    for (size_t i = 0; i < m; ++i) {
        unsigned& x = a[r[i].first-1];
        if (x == r[i].second)
            continue;

        s[x].back().second = i;
        x = r[i].second;
        s[x].emplace_back(i + 1, m);
    }

    integer k = n * m * (m + 1) / 2;
    for (const std::vector<std::pair<unsigned, unsigned>>& v : s) {
        unsigned d = 0;
        for (auto it = v.rbegin(); it != v.rend(); ++it) {
            const unsigned q = it->second - it->first + 1;
            k += q * (m - it->second - d);
            d += q;
        }
    }

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(a, r);
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
