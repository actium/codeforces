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

void solve(const std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    const auto f = [&](unsigned d) {
        size_t c = 0;
        for (size_t i = 0; i < n; i = search(i+1, n, [&](size_t j) { return a[j] - a[i] >= d; }))
            ++c;

        return c < k;
    };

    answer(search(1, 1000000000, f) - 1);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

