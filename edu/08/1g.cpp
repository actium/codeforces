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

void answer(size_t u, const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << u << ' ' << v.size() << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(std::vector<unsigned>& a)
{
    std::sort(a.begin(), a.end());

    const size_t k = a.back() + (a.front() == 0 ? 2 : 1);

    std::vector<std::pair<unsigned, unsigned>> e;
    for (size_t lb = (a[0] == 0), ub = a.size(), x = lb; lb < ub; ++lb, --ub) {
        for (size_t i = 0; i < a[lb]; ++i) {
            for (size_t j = i + 1; j <= a[ub-1]; ++j)
                e.emplace_back(1 + x + i, 1 + x + j);
        }

        x += a[lb];

        for (size_t i = lb + 1; i < ub; ++i)
            a[i] -= a[lb];
    }

    answer(k, e);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
