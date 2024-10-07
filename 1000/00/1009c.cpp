#include <iostream>
#include <vector>

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

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(unsigned n, const std::vector<std::pair<int, int>>& q)
{
    long long a = 0, pd = 0, nd = 0;
    for (const std::pair<int, int>& e : q) {
        a += e.first;
        (e.second < 0 ? nd : pd) += e.second;
    }

    const auto sum = [](long long n) {
        return n * (n - 1) / 2;
    };

    const long long s = sum(n) * pd + sum((n + 1) / 2) * nd + sum(n - (n - 1) / 2) * nd;

    answer(a + double(s) / n);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> q(m);
    std::cin >> q;

    solve(n, q);

    return 0;
}
