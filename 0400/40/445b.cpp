#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void traverse(const std::vector<std::vector<size_t>>& g, size_t i, integer& t)
{
    t |= 1ull << i;

    for (const size_t j : g[i]) {
        if ((t & 1ull << j) == 0)
            traverse(g, j, t);
    }
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    std::vector<std::vector<size_t>> g(n);
    for (const auto& e : r) {
        g[e.first-1].push_back(e.second-1);
        g[e.second-1].push_back(e.first-1);
    }

    integer t = 0, k = 0;
    for (size_t i = 0; i < n; ++i) {
        if ((t & 1ull << i) == 0) {
            traverse(g, i, t);
            ++k;
        }
    }

    answer(1ull << (n - k));
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(n, r);

    return 0;
}
