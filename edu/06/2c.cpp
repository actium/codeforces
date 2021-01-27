#include <iostream>

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

void solve(unsigned n, unsigned x, unsigned y)
{
    unsigned d = std::min(x, y);
    if (n > 1)
        d += search(0u, n * 10, [=](unsigned t) { return 1 + t / x + t / y >= n; });

    answer(d);
}

int main()
{
    unsigned n, x, y;
    std::cin >> n >> x >> y;

    solve(n, x, y);

    return 0;
}

