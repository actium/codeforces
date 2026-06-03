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

void solve(const std::vector<int>& a, const std::vector<unsigned>& x)
{
    const size_t n = a.size();

    std::vector<int> q[2];
    for (size_t i = 0; i < n; ++i)
        q[i % 2].push_back(a[i]);

    unsigned f[2] = {};
    for (const auto p : x)
        ++f[(p-1) % 2];

    integer s = 0;
    for (size_t i = 0; i < 2; ++i) {
        if (f[i] != 0) {
            std::sort(q[i].begin(), q[i].end());

            do {
                q[i].pop_back();
            } while (--f[i] != 0 && !q[i].empty() && q[i].back() > 0);
        }

        for (const auto v : q[i])
            s += v;
    }

    answer(s);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::cin >> a;

    std::vector<unsigned> x(m);
    std::cin >> x;

    solve(a, x);
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
