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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, size_t k)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t x, size_t y) { return a[x] + b[y] < a[y] + b[x]; });

    unsigned s = 0;
    for (size_t i = 0; i < n; ++i) {
        const size_t x = p[i];
        s += (i < k || a[x] < b[x] ? a[x] : b[x]);
    }

    answer(s);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, k);

    return 0;
}

