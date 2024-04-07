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

void answer(unsigned x, int y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<int>& a, unsigned k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), std::greater<int>());

    std::vector<integer> d(n);
    for (size_t i = 1; i < n; ++i)
        d[i] = d[i-1] + a[0] - a[i];

    const auto count = [&](size_t x) {
        size_t lb = x, ub = n;
        while (lb + 1 < ub) {
            const size_t mid = (lb + ub) / 2;
            (d[mid] - d[x] - integer(mid - x) * (a[0] - a[x]) <= k ? lb : ub) = mid;
        }
        return ub - x;
    };

    std::pair<unsigned, int> x = { 0, 0 };
    for (size_t i = 0; i < n; ++i) {
        const unsigned c = count(i);
        if (c >= x.first)
            x = std::make_pair(c, a[i]);
    }

    answer(x.first, x.second);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
