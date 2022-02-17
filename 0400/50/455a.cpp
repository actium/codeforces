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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a)
{
    unsigned f[1 + 100000 + 1] = {};
    for (const unsigned x : a)
        ++f[x];

    integer dp[1 + 100000] = { 0, f[1] };
    for (integer x = 2; x <= 100000; ++x)
        dp[x] = std::max(dp[x-2] + f[x] * x, dp[x-1]);

    answer(dp[100000]);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
