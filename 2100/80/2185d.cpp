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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& d, unsigned h)
{
    const size_t n = a.size(), m = d.size();

    std::vector<std::pair<unsigned, unsigned>> v(n);
    for (size_t i = 0; i < n; ++i)
        v[i].first = a[i];

    unsigned t = 0;
    for (size_t i = 0; i < m; ++i) {
        const size_t x = d[i].first - 1;
        if (v[x].second < t) {
            v[x].first = a[x];
            v[x].second = t;
        }
        v[x].first += d[i].second;
        t += (v[x].first > h);
    }

    for (size_t i = 0; i < n; ++i) {
        if (v[i].second == t)
            a[i] = v[i].first;
    }

    answer(a);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned h;
    std::cin >> h;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> d(m);
    std::cin >> d;

    solve(a, d, h);
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
