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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned solve(const std::vector<unsigned>& q, unsigned a, unsigned b, unsigned c)
{
    const size_t n = q.size();

    std::vector<unsigned> p(1+n);
    {
        unsigned t = 0;
        for (size_t i = 0; i < n; ++i) {
            t += q[i];
            p[i+1] = p[i] + (t == a);
        }
    }

    unsigned k = 0;
    {
        unsigned t = 0;
        for (size_t i = n-1; i > 0; --i) {
            t += q[i];
            k += (t == c) * p[i-1];
        }
    }

    return k;
}

void solve(const std::vector<std::vector<unsigned>>& q, unsigned a, unsigned b, unsigned c)
{
    const size_t n = q.size(), m = q[0].size();

    std::vector<unsigned> h(n), v(m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            h[i] += q[i][j];
            v[j] += q[i][j];
        }
    }

    unsigned s = 0;
    for (const unsigned x : h)
        s += x;

    if (s != a + b + c)
        return answer(0);

    std::vector<unsigned> p = { a, b, c };
    std::sort(p.begin(), p.end());

    unsigned k = 0;
    do {
        k += solve(h, p[0], p[1], p[2]);
        k += solve(v, p[0], p[1], p[2]);
    } while (std::next_permutation(p.begin(), p.end()));

    answer(k);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> q(n, std::vector<unsigned>(m));
    std::cin >> q;

    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(q, a, b, c);

    return 0;
}
