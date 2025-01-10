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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, integer x, integer y)
{
    integer s = 0;
    for (const unsigned v : a)
        s += v;

    if (s < x)
        return answer(0);

    const integer min_decrease = (s > y ? s - y : 0), max_decrease = s - x;

    std::sort(a.begin(), a.end());

    integer k = 0;
    for (auto it = a.begin(); it != a.end() && *it < max_decrease; ++it) {
        const auto lb = std::lower_bound(std::next(it), a.end(), *it < min_decrease ? min_decrease - *it : 0);
        const auto ub = std::upper_bound(std::next(it), a.end(), max_decrease - *it);
        k += ub - lb;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer x, y;
    std::cin >> x >> y;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x, y);
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
