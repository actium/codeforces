#include <algorithm>
#include <iostream>
#include <vector>

using integer = long long;

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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    integer lb = 0, ub = 0, x = a[0];
    for (size_t i = 0; i < n; ++i) {
        const auto q = std::max(a[i] - lb, a[i] + ub);
        x = std::max(x, q);

        lb = std::min<integer>({ a[i], lb + a[i], lb + a[i] + lb });
        ub = std::max<integer>({ a[i], ub + a[i], ub + a[i] + ub });
    }

    answer(x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);
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
