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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned ta, unsigned tb, size_t k)
{
    const size_t n = a.size(), m = b.size();

    if (k >= n || k >= m)
        return no_answer();

    unsigned t = 0;
    for (size_t i = 0; i <= k; ++i) {
        const size_t x = std::lower_bound(b.begin(), b.end(), a[i] + ta) - b.begin();
        if (x + k - i >= m)
            return no_answer();

        t = std::max(t, b[x+k-i] + tb);
    }

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    unsigned ta, tb;
    std::cin >> ta >> tb;

    size_t k;
    std::cin >> k;

    std::vector<unsigned> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b, ta, tb, k);

    return 0;
}
