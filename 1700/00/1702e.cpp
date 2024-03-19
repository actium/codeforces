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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool paint(const std::vector<std::pair<unsigned, unsigned>>& p, const std::vector<std::vector<size_t>>& x, unsigned u, std::vector<unsigned>& c)
{
    const size_t i = x[u][0], j = x[u][1];
    if (c[i] != 0 && c[j] != 0)
        return c[i] != c[j];

    if (c[i] == 0 && c[j] == 0) {
        c[i] = 1;
        c[j] = 2;
    }

    if (c[i] == 0)
        c[i] = 3 - c[j];

    if (c[j] == 0)
        c[j] = 3 - c[i];

    return paint(p, x, p[i].first, c) && paint(p, x, p[i].second, c) && paint(p, x, p[j].first, c) && paint(p, x, p[j].second, c);
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& p)
{
    const size_t n = p.size();

    std::vector<std::vector<size_t>> x(1 + n);
    for (size_t i = 0; i < n; ++i) {
        if (p[i].first == p[i].second)
            return answer(false);

        x[p[i].first].push_back(i);
        if (x[p[i].first].size() == 3)
            return answer(false);

        x[p[i].second].push_back(i);
        if (x[p[i].second].size() == 3)
            return answer(false);
    }

    std::vector<unsigned> c(n);
    for (unsigned i = 1; i <= n; ++i) {
        if (!x[i].empty() && !paint(p, x, i, c))
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> p(n);
    std::cin >> p;

    solve(p);
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
