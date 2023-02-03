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

void solve(const std::vector<unsigned>& c)
{
    const size_t m = c.size(), n = 2 * m + 1;

    std::vector<unsigned> v;
    v.reserve(n);
    v.insert(v.end(), c.begin(), c.end()); v.push_back(0); v.insert(v.end(), c.rbegin(), c.rend());

    std::vector<unsigned> z(n);
    for (size_t i = 1, j = 0; i < n; ++i) {
        unsigned& p = z[i];
        if (j + z[j] > i)
            p = std::min<unsigned>(j + z[j] - i, z[i - j]);

        while (i + p < n && v[p] == v[i + p])
            ++p;

        if (j + z[j] < i + p)
            j = i;
    }

    std::vector<unsigned> q;
    for (size_t i = m / 2; i > 0; --i) {
        if (z[n - 2 * i] >= i)
            q.push_back(m - i);
    }
    q.push_back(m);

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c);

    return 0;
}
