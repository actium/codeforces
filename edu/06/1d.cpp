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

template <typename T, typename F>
T search(T lb, T ub, F&& f)
{
    if (f(lb))
        return lb;

    for (auto k = ub - lb; k > 1; ) {
        const auto half = k / 2;
        if (!f(lb + half))
            lb += half;

        k -= half;
    }
    return lb + 1;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& a, int l, int r)
{
    const auto lb = search(a.cbegin(), a.cend(), [l](auto it) { return *it >= l; });
    const auto ub = search(a.cbegin(), a.cend(), [r](auto it) { return *it > r; });

    answer(ub - lb);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    std::sort(a.begin(), a.end());

    unsigned k;
    std::cin >> k;

    while (k-- > 0) {
        int l, r;
        std::cin >> l >> r;

        solve(a, l, r);
    }

    return 0;
}

