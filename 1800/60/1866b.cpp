#include <iostream>
#include <vector>

using vector_t = std::vector<unsigned>;

constexpr unsigned M = 998244353;

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

void solve(const vector_t& a, const vector_t& b, const vector_t& c, const vector_t& d)
{
    const size_t n = a.size(), m = c.size();

    unsigned k = 1;
    for (size_t i = 0, j = 0; i < n || j < m; ++i) {
        if (i == n)
            return answer(0);

        if (j == m || a[i] < c[j]) {
            k *= 2;
            k %= M;
            continue;
        }

        if (a[i] > c[j] || b[i] < d[j])
            return answer(0);

        if (b[i] != d[j++]) {
            k *= 2;
            k %= M;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    vector_t a(n), b(n);
    std::cin >> a >> b;

    size_t m;
    std::cin >> m;

    vector_t c(m), d(m);
    std::cin >> c >> d;

    solve(a, b, c, d);

    return 0;
}

/*
0 -> 1
1 -> 2
2 -> 4
3 -> 8
4 -> 16

*/