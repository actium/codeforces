#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, std::vector<unsigned>& b, const std::string& s)
{
    const size_t n = a.size(), k = s.length();

    std::sort(b.begin(), b.end());

    std::vector<unsigned> d[2];
    for (size_t i = 0; i < 2; ++i)
        d[i].resize(n, oo);

    std::vector<std::vector<size_t>> q[2];
    for (size_t i = 0; i < 2; ++i)
        q[i].resize(1+k);

    for (size_t i = 0; i < n; ++i) {
        const auto r = std::equal_range(b.begin(), b.end(), a[i]);

        if (r.second != b.begin()) {
            const unsigned dx = a[i] - *std::prev(r.second);
            d[0][i] = dx;
            if (dx <= k)
                q[0][dx].push_back(i);
        }
        if (r.first != b.end()) {
            const unsigned dx = *r.first - a[i];
            d[1][i] = dx;
            if (dx <= k)
                q[1][dx].push_back(i);
        }
    }

    std::vector<unsigned> v(k);
    {
        std::vector<unsigned> c(n, 1);

        const auto count = [&](std::vector<std::vector<size_t>>& q, unsigned dx) {
            unsigned k = 0;
            for (const size_t i : q[dx]) {
                k += c[i];
                c[i] = 0;
            }
            q[dx].clear();
            return k;
        };

        int x = 0;
        for (size_t i = 0, r = n; i < k; ++i) {
            x += (s[i] == 'L' ? -1 : +1);
            r -= (x < 0 ? count(q[0], -x) : count(q[1], x));
            v[i] = r;
        }
    }

    answer(v);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    std::string s;
    std::cin >> s;

    solve(a, b, s);
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
