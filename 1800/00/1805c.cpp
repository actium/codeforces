#include <algorithm>
#include <iostream>
#include <vector>

#include <cmath>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<std::vector<int>>& q, std::vector<int>& k)
{
    std::sort(k.begin(), k.end());

    for (const std::vector<int>& x : q) {
        const int a = x[0], b = x[1], c = x[2];

        const double d = 2 * sqrt(1ll * a * c), lb = b - d, ub = b + d;

        auto it = std::lower_bound(k.begin(), k.end(), lb);
        while (it != k.end() && *it <= lb)
            ++it;

        if (it != k.end() && *it < ub)
            answer(*it);
        else
            no_answer();
    }
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> k(n);
    std::cin >> k;

    std::vector<std::vector<int>> q(m, std::vector<int>(3));
    std::cin >> q;

    solve(q, k);
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
