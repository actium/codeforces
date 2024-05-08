#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

int search(const std::vector<unsigned>& p, size_t u, size_t x, unsigned d, std::vector<bool>& v)
{
    if (v[u])
        return u == x ? d : -1;

    v[u] = true;
    return search(p, p[u]-1, x, d + 1, v);
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    std::vector<unsigned> s;
    {
        std::vector<bool> v(n);
        for (size_t i = 0; i < n; ++i) {
            if (v[i])
                continue;

            const int c = search(p, i, i, 0, v);
            if (c == -1)
                return no_answer();

            s.push_back(c);
        }
    }

    unsigned m = 1;
    for (const unsigned x : s)
        m = std::lcm(m, x);

    answer(m % 2 == 0 ? m / 2 : m);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
