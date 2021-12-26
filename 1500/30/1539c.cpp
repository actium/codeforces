#include <algorithm>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<integer>& a, integer k, integer x)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<integer> gaps;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] - a[i-1] > x)
            gaps.push_back(a[i] - a[i-1]);
    }

    std::sort(gaps.begin(), gaps.end(), std::greater<integer>());
    while (!gaps.empty() && (gaps.back() - 1) / x <= k) {
        k -= (gaps.back() - 1) / x;
        gaps.pop_back();
    }

    answer(gaps.size() + 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    integer k, x;
    std::cin >> k >> x;

    std::vector<integer> a(n);
    std::cin >> a;

    solve(a, k, x);

    return 0;
}
