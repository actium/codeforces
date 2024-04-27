#include <iostream>
#include <vector>

constexpr long long oo = ~0u;

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

void answer(long long x)
{
    std::cout << x << '\n';
}

void infinity()
{
    std::cout << "Infinity" << '\n';
}

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void solve(const std::vector<std::pair<int, unsigned>>& r)
{
    long long lb = -oo, ub = oo;
    for (const auto& [c, d] : r) {
        if (d == 1)
            lb = std::max(lb, 1900LL);
        else
            ub = std::min(ub, 1899LL);

        if (lb > ub)
            return no_answer();

        lb = std::max<long long>(lb + c, -oo);
        ub = std::min<long long>(ub + c, oo);
    }

    2 * ub < oo ? answer(ub) : infinity();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<int, unsigned>> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}
