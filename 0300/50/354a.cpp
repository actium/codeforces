#include <iostream>
#include <vector>

using pair_t = std::pair<unsigned, unsigned>;

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

void solve(const std::vector<unsigned>& w, const pair_t& p, const pair_t& q)
{
    const size_t n = w.size();

    std::vector<unsigned> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + w[i];

    const auto extra = [&](unsigned k) -> unsigned {
        if (k > n - k)
            return (2 * k - n - 1) * q.first;

        if (k < n - k)
            return (n - 2 * k - 1) * q.second;

        return 0;
    };

    unsigned t = ~0u;
    for (size_t k = 0; k <= n; ++k)
        t = std::min(t, ps[k] * p.first + (ps[n] - ps[k]) * p.second + extra(k));

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    pair_t p, q;
    std::cin >> p >> q;

    std::vector<unsigned> w(n);
    std::cin >> w;

    solve(w, p, q);

    return 0;
}