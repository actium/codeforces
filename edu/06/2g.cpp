#include <iostream>
#include <vector>

using count_t = unsigned long long;

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
    for (auto k = ub - lb; k > 1; ) {
        const auto half = k / 2;
        if (!f(lb + half))
            lb += half;

        k -= half;
    }
    return lb;
}

void answer(count_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned k, const std::vector<unsigned>& a)
{
    const auto f = [&](count_t q) {
        count_t d = 0;
        for (const unsigned x : a)
            d += std::min<count_t>(q, x);

        return d < q * k;
    };

    answer(search(0ull, 25000000001ull, f));
}

int main()
{
    unsigned k;
    std::cin >> k;

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(k, a);

    return 0;
}

