#include <array>
#include <iostream>
#include <vector>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
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

void solve(const std::vector<std::array<unsigned, 3>>& q)
{
    const size_t n = q.size() + 2;

    std::vector<std::vector<unsigned>> g(1 + n);
    for (const std::array<unsigned, 3>& a : q) {
        for (size_t i = 1; i < 3; ++i) {
            for (size_t j = 0; j < i; ++j) {
                g[a[i]].push_back(a[j]);
                g[a[j]].push_back(a[i]);
            }
        }
    }

    std::vector<unsigned> p;
    {
        std::vector<bool> v(1 + n);

        const auto append = [&](unsigned x) {
            p.push_back(x);
            v[x] = true;
        };

        unsigned s = 1;
        while (g[s].size() != 2)
            ++s;

        append(s);

        for (size_t i = 0; i < n; ++i) {
            std::vector<unsigned> c;
            for (const unsigned u : g[p[i]]) {
                if (!v[u])
                    c.push_back(u);
            }

            if (c.size() == 2 && g[c[0]].size() > g[c[1]].size())
                std::swap(c[0], c[1]);

            for (const unsigned u : c)
                append(u);
        }
    }

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::array<unsigned, 3>> q(n-2);
    std::cin >> q;

    solve(q);

    return 0;
}
