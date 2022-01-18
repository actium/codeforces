#include <iostream>
#include <vector>

using interval_t = std::pair<unsigned, unsigned>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<interval_t>& d, size_t k, const std::vector<interval_t>& r)
{
    constexpr size_t N = 200000;

    unsigned da[1+N] = {};
    for (const interval_t& x : d) {
        ++da[x.first];
        --da[x.second+1];
    }

    unsigned f[1+N] = {};
    for (size_t i = 1; i < 1+N; ++i) {
        da[i] += da[i-1];
        f[i] += f[i-1] + (da[i] >= k);
    }

    for (const interval_t& x : r)
        answer(f[x.second] - f[x.first-1]);
}

int main()
{
    size_t n, k, q;
    std::cin >> n >> k >> q;

    std::vector<interval_t> d(n), r(q);
    std::cin >> d >> r;

    solve(d, k, r);

    return 0;
}
