#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const auto [x, y] : v)
        std::cout << 1+x << ' ' << 1+y << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned x, unsigned y)
{
    const size_t n = a.size(), m = b.size();

    std::vector<std::pair<size_t, size_t>> p;
    for (size_t i = 0, j = 0; i < n && j < m; ++i) {
        while (j < m && b[j] + x < a[i])
            ++j;

        if (j < m && b[j] <= a[i] + y)
            p.emplace_back(i, j++);
    }

    answer(p);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned x, y;
    std::cin >> x >> y;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(a, b, x, y);

    return 0;
}

