#include <iostream>
#include <tuple>
#include <vector>

using integer = unsigned long long;

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

void solve(const std::vector<unsigned>& h1, const std::vector<unsigned>& h2)
{
    const size_t n = h1.size();

    integer dp1 = 0, dp2 = 0;
    for (size_t i = 0; i < n; ++i)
        std::tie(dp1, dp2) = std::make_tuple(std::max(dp1, dp2 + h1[i]), std::max(dp2, dp1 + h2[i]));

    answer(std::max(dp1, dp2));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> h1(n), h2(n);
    std::cin >> h1 >> h2;

    solve(h1, h2);

    return 0;
}
