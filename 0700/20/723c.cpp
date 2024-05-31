#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned u, unsigned v, const std::vector<unsigned>& w)
{
    std::cout << u << ' ' << v << '\n';

    const char* separator = "";
    for (const unsigned x : w) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a, size_t m)
{
    const size_t n = a.size(), k = n / m;

    std::vector<size_t> f(m), p[2];
    for (size_t i = 0; i < n; ++i) {
        if (a[i] <= m && f[a[i]-1] < k)
            ++f[a[i]-1];
        else
            p[a[i] > m].push_back(i);
    }

    unsigned d = 0;
    for (size_t i = 0; i < m; ++i) {
        while (f[i] < k) {
            if (p[1].empty())
                std::swap(p[0], p[1]);

            a[p[1].back()] = i + 1;
            p[1].pop_back();

            ++f[i];
            ++d;
        }
    }

    answer(k, d, a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);

    return 0;
}
