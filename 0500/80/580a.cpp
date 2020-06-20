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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<size_t>& a)
{
    const size_t n = a.size();

    std::vector<size_t> dp(n, 1);
    for (size_t i = 1; i < n; ++i) {
        if (a[i] >= a[i-1])
            dp[i] = dp[i-1] + 1;
    }

    answer(*std::max_element(dp.cbegin(), dp.cend()));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

