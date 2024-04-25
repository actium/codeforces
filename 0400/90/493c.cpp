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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ':' << y << '\n';
}

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = a.size(), m = b.size();

    std::vector<unsigned> c;
    c.insert(c.end(), a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());

    std::sort(c.begin(), c.end());
    c.erase(std::unique(c.begin(), c.end()), c.end());

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    unsigned s = n * 3, t = m * 3;
    for (const unsigned x : c) {
        const size_t p = std::upper_bound(a.begin(), a.end(), x) - a.begin();
        const size_t q = std::upper_bound(b.begin(), b.end(), x) - b.begin();

        const unsigned u = p * 2 + (n - p) * 3, v = q * 2 + (m - q) * 3;
        if (u + t > v + s || u + t == v + s && u > s) {
            s = u;
            t = v;
        }
    }

    answer(s, t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(a, b);

    return 0;
}
