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

void solve(std::vector<unsigned>& a, integer k)
{
    const size_t n = a.size();

    integer s = 0;
    for (const unsigned x : a)
        s += x;

    if (s <= k)
        return answer(0);

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    std::vector<integer> p(1 + n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + (a[i] - a[n-1]);

    const auto check = [&](integer x) {
        for (size_t i = 1; i < n && i <= x; ++i) {
            const integer d = p[i] + (i + 1) * (x - i);
            if (k + d >= s)
                return true;
        }
        return false;
    };

    integer lb = 0, ub = s - k;
    while (lb + 1 < ub) {
        const integer mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
