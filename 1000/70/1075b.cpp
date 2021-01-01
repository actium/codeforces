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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& p, const std::vector<unsigned>& t)
{
    const size_t n = p.size(), m = t.size();

    std::sort(p.begin(), p.end());

    std::vector<size_t> x(m);
    for (size_t i = 0; i < m; ++i)
        x[i] = i;

    std::sort(x.begin(), x.end(), [&t](size_t a, size_t b) { return t[a] < t[b]; });

    std::vector<unsigned> c(m);
    for (size_t i = 0, j = 0; i < m; ++i) {
        for (unsigned ub = i + 1 < m ? (t[x[i]] + t[x[i+1]]) / 2 : p.back(); j < n && p[j] <= ub; ++j)
            ++c[x[i]];
    }

    answer(c);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> x(n + m);
    std::cin >> x;

    std::vector<unsigned> p[2];
    for (size_t i = 0; i < n + m; ++i) {
        unsigned a;
        std::cin >> a;

        p[a].push_back(x[i]);
    }

    solve(p[0], p[1]);

    return 0;
}

