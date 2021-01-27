#include <iostream>

using length_t = unsigned long long;

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

void answer(length_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned w, unsigned h, unsigned n)
{
    const auto f = [=](length_t x) {
        if (x / w >= n && x / h >= 1)
            return true;

        if (x / h >= n && x / w >= 1)
            return true;

        return (x / w) * (x / h) >= n;
    };

    answer(search<length_t>(0, n * std::max<length_t>(w, h), f));
}

int main()
{
    unsigned w, h, n;
    std::cin >> w >> h >> n;

    solve(w, h, n);

    return 0;
}

