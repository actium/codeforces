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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::pair<int, int>>& p)
{
    int lb = p[0].first, ub = p[0].first;
    for (size_t i = 1; i < 4; ++i) {
        lb = std::min(lb, p[i].first);
        ub = std::max(ub, p[i].first);
    }

    answer((ub - lb) * (ub - lb));
}

void test_case()
{
    std::vector<std::pair<int, int>> p(4);
    std::cin >> p;

    solve(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
