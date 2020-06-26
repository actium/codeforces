#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<size_t>& b)
{
    const size_t n = a.size();
    const size_t m = b.size();

    std::vector<std::pair<size_t, size_t>> index(n, std::make_pair(n, n));
    for (size_t i = 0; i < n; ++i) {
        auto& p = index[a[i] - 1];
        p.first = std::min(p.first, i + 1);
        p.second = std::min(p.second, n - i);
    }

    std::pair<integer, integer> f = { 0, 0 };
    for (size_t i = 0; i < m; ++i) {
        const auto& p = index[b[i] - 1];
        f.first += p.first;
        f.second += p.second;
    }

    answer(f.first, f.second);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<size_t> b(m);
    std::cin >> b;

    solve(a, b);

    return 0;
}

