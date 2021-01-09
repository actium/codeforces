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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

std::vector<unsigned> primes(unsigned ub)
{
    std::vector<unsigned> p(ub);
    for (size_t i = 2; i < ub; ++i) {
        if (p[i] != 0)
            continue;

        for (size_t j = i; j < ub; j += i)
            p[j] = i;
    }

    unsigned x = ~0u;
    for (size_t i = ub; i-- > 0; ) {
        if (p[i] != i)
            p[i] = x;
        else
            x = p[i];
    }
    return p;
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size(), m = a[0].size();

    const std::vector<unsigned> p = primes(100005);

    std::vector<unsigned> r(n), c(m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            r[i] += p[a[i][j]] - a[i][j];
            c[j] += p[a[i][j]] - a[i][j];
        }
    }

    const unsigned x = *std::min_element(r.begin(), r.end());
    const unsigned y = *std::min_element(c.begin(), c.end());

    answer(std::min(x, y));
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(m));
    std::cin >> a;

    solve(a);

    return 0;
}

