#include <iostream>

using integer = unsigned long long;

template <typename T, typename F>
T search(T lb, T ub, F&& f)
{
    for (auto k = ub - lb; k > 1; ) {
        const auto half = k / 2;
        if (!f(lb + half))
            lb += half;

        k -= half;
    }
    return lb;
};

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n, integer k)
{
    const auto f = [&](integer x) {
        integer c = 0;
        for (integer i = 1; i <= n; ++i)
            c += std::min((x - 1) / i, n);

        return c >= k;
    };

    answer(search<integer>(1, n * n + 1, f));
}

int main()
{
    integer n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

