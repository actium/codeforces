#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned x)
{
    const size_t n = a.size(), m = b.size();

    std::vector<unsigned> p(n, oo);
    for (size_t i = 0; i < n; ++i) {
        unsigned t = 0;
        for (size_t j = i; j < n; ++j) {
            t += a[j];
            p[j-i] = std::min(p[j-i], t);
        }
    }

    std::vector<unsigned> q(m, oo);
    for (size_t i = 0; i < m; ++i) {
        unsigned t = 0;
        for (size_t j = i; j < m; ++j) {
            t += b[j];
            q[j-i] = std::min(q[j-i], t);
        }
    }

    unsigned v = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (1ull * p[i] * q[j] <= x)
                v = std::max<unsigned>(v, (i + 1) * (j + 1));
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    unsigned x;
    std::cin >> x;

    solve(a, b, x);

    return 0;
}
