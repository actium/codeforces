#include <algorithm>
#include <iostream>
#include <vector>

constexpr unsigned K = 10000000;

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

void solve(const std::vector<unsigned>& x, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    std::vector<unsigned> spf(1+K), primes;
    for (unsigned i = 2; i <= K; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (const unsigned p : primes) {
            if (p > spf[i] || i * p > K)
                break;

            spf[i*p] = p;
        }
    }

    std::vector<unsigned> p;
    for (unsigned v : x) {
        while (v != 1) {
            p.push_back(spf[v]);

            while (spf[v] == p.back())
                v /= p.back();
        }
    }

    std::sort(p.begin(), p.end());

    for (const auto& [lb, ub] : r)
        answer(std::upper_bound(p.begin(), p.end(), ub) - std::lower_bound(p.begin(), p.end(), lb));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n);
    std::cin >> x;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    solve(x, r);

    return 0;
}
