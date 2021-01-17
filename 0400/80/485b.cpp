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

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::pair<int, int>>& p)
{
    std::pair<int, int> lb = p[0], ub = p[0];
    for (const auto [x, y] : p) {
        lb.first = std::min(lb.first, x);
        lb.second = std::min(lb.second, y);
        ub.first = std::max(ub.first, x);
        ub.second = std::max(ub.second, y);
    }

    const long long d = std::max(ub.first - lb.first, ub.second - lb.second);

    answer(d * d);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<int, int>> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}

