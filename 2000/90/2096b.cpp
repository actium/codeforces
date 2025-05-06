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

void solve(const std::vector<unsigned>& ls, const std::vector<unsigned>& rs, size_t k)
{
    const size_t n = ls.size();

    std::vector<unsigned> u(n), v(n);
    for (size_t i = 0; i < n; ++i) {
        u[i] = std::max(ls[i], rs[i]);
        v[i] = std::min(ls[i], rs[i]);
    }

    integer w = 0;
    for (size_t i = 0; i < n; ++i)
        w += u[i];

    std::sort(v.begin(), v.end(), std::greater<unsigned>());
    for (size_t i = 0; i < k - 1; ++i)
        w += v[i];

    answer(w + 1);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> ls(n), rs(n);
    std::cin >> ls >> rs;

    solve(ls, rs, k);
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
