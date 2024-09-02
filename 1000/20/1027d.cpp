#include <iostream>
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

void traverse(const std::vector<unsigned>& a, size_t u, std::vector<unsigned>& v, std::vector<size_t>& p, std::vector<std::vector<size_t>>& cycles)
{
    if (v[u] == 2)
        return;

    p.push_back(u);

    if (v[u] == 1) {
        cycles.emplace_back();
        do {
            cycles.back().push_back(p.back());
            p.pop_back();
        } while (p.back() != u);
    } else {
        v[u] = 1;
        traverse(a, a[u]-1, v, p, cycles);
    }

    v[u] = 2;
}

void solve(const std::vector<unsigned>& c, const std::vector<unsigned>& a)
{
    const size_t n = c.size();

    std::vector<std::vector<size_t>> cycles;
    {
        std::vector<unsigned> v(n);
        for (size_t i = 0; i < n; ++i) {
            std::vector<size_t> p;
            traverse(a, i, v, p, cycles);
        }
    }

    unsigned t = 0;
    for (const std::vector<size_t>& cycle : cycles) {
        unsigned d = ~0u;
        for (const size_t x : cycle)
            d = std::min(d, c[x]);

        t += d;
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n), a(n);
    std::cin >> c >> a;

    solve(c, a);

    return 0;
}
