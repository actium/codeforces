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

struct Movie {
    std::string s;
    std::vector<unsigned> b;
};

std::istream& operator >>(std::istream& input, Movie& f)
{
    input >> f.s;

    size_t d;
    input >> d;

    f.b.resize(d);
    return input >> f.b;
}

void answer(const std::vector<unsigned>& v)
{
    for (const unsigned x : v)
        std::cout << x << '\n';
}

std::pair<unsigned, unsigned> count(const Movie& f, size_t m, const std::vector<unsigned>& a)
{
    std::pair<unsigned, unsigned> q = { 0, 0 };

    unsigned u = m - a.size();
    for (const unsigned x : f.b) {
        const auto it = std::find(a.begin(), a.end(), x);
        if (it != a.end() || u == 0) {
            ++q.first;
            q.second += (it != a.end());
        } else {
            --u;
        }
        q.second += (x == 0);
    }
    q.second = std::min<unsigned>(q.second, a.size());
    return q;
}

void solve(size_t m, const std::vector<unsigned>& a, const std::vector<Movie>& f)
{
    const size_t n = f.size();

    std::vector<std::pair<unsigned, unsigned>> c(n);
    for (size_t i = 0; i < n; ++i)
        c[i] = count(f[i], m, a);

    std::vector<std::pair<unsigned, unsigned>> h(1+m);

    const auto update = [&](unsigned u, unsigned v, int d) {
        h[u].first += d;
        h[v].second += d;
    };

    for (size_t i = 0; i < n; ++i)
        update(c[i].first, c[i].second, 1);

    const auto check = [&](size_t x) {
        for (size_t i = c[x].second + 1; i <= m; ++i) {
            if (h[i].first != 0)
                return 1;
        }
        for (size_t i = c[x].first + 1; i <= m; ++i) {
            if (h[i].second != 0)
                return 2;
        }
        return 0;
    };

    std::vector<unsigned> s(n);
    for (size_t i = 0; i < n; ++i) {
        update(c[i].first, c[i].second, -1);
        s[i] = check(i);
        update(c[i].first, c[i].second, 1);
    }

    answer(s);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t m, k;
    std::cin >> m >> k;

    std::vector<unsigned> a(k);
    std::cin >> a;

    size_t n;
    std::cin >> n;

    std::vector<Movie> f(n);
    std::cin >> f;

    solve(m, a, f);

    return 0;
}
