#include <iostream>
#include <vector>

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

using integer = unsigned long long;

template <typename Iterator>
std::vector<integer> f(Iterator cursor, size_t n)
{
    std::vector<integer> g(n);
    {
        g[0] = cursor[0];

        std::vector<std::pair<unsigned, unsigned>> s;
        s.emplace_back(cursor[0], 1);
        for (size_t i = 1; i < n; ++i) {
            g[i] = g[i-1] + cursor[i];

            unsigned k = 1;
            while (!s.empty() && cursor[i] <= s.back().first) {
                k += s.back().second;
                g[i] -= s.back().second * integer(s.back().first - cursor[i]);
                s.pop_back();
            }

            if (s.empty() || cursor[i] > s.back().first)
                s.emplace_back(cursor[i], k);
            else
                ++s.back().second;
        }
    }
    return g;
}

void solve(const std::vector<unsigned>& m)
{
    const size_t n = m.size();

    const std::vector<integer> p = f(m.begin(), n);
    const std::vector<integer> s = f(m.rbegin(), n);

    std::pair<integer, size_t> v = { 0, n };
    for (size_t i = 0; i < n; ++i) {
        if (p[i] + s[n-1-i] - m[i] > v.first) {
            v.first = p[i] + s[n-1-i] - m[i];
            v.second = i;
        }
    }

    std::vector<unsigned> a(n);
    a[v.second] = m[v.second];
    for (size_t i = v.second + 1; i < n; ++i)
        a[i] = std::min(a[i-1], m[i]);
    for (size_t i = v.second - 1; ~i != 0; --i)
        a[i] = std::min(m[i], a[i+1]);

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> m(n);
    std::cin >> m;

    solve(m);

    return 0;
}
