#include <algorithm>
#include <iostream>
#include <string>
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

void explore(const std::vector<std::string>& a, size_t u, std::vector<bool>& v, std::vector<size_t>& x)
{
    const size_t n = a.size();

    x.push_back(u);
    v[u] = true;

    for (size_t i = 0; i < n; ++i) {
        if (i != u && !v[i] && a[u][i] == '1')
            explore(a, i, v, x);
    }
}

void solve(std::vector<unsigned>& p, const std::vector<std::string>& a)
{
    const size_t n = p.size();

    std::vector<bool> v(n);
    for (size_t i = 0; i < n; ++i) {
        if (v[i])
            continue;

        std::vector<size_t> x;
        explore(a, i, v, x);

        std::vector<unsigned> s;
        for (const size_t j : x)
            s.push_back(p[j]);

        std::sort(s.begin(), s.end());
        std::sort(x.begin(), x.end());

        for (size_t j = 0; j < x.size(); ++j)
            p[x[j]] = s[j];
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(p, a);

    return 0;
}
