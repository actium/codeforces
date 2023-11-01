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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned s)
{
    const size_t n = a.size();

    const auto f = [&](size_t k) {
        std::vector<integer> b(n);
        for (size_t i = 0; i < n; ++i)
            b[i] = a[i] + (i + 1ull) * k;

        std::sort(b.begin(), b.end());

        for (size_t i = 1; i < k; ++i)
            b[i] += b[i-1];

        return b[k-1];
    };

    size_t lb = 0, ub = n + 1;
    while (lb + 1 < ub) {
        const size_t mid = (lb + ub) / 2;
        (f(mid) <= s ? lb : ub) = mid;
    }

    answer(lb, lb != 0 ? f(lb) : 0);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, s);

    return 0;
}
