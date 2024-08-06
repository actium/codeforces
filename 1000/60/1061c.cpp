#include <algorithm>
#include <iostream>
#include <vector>

constexpr unsigned M = 1'000'000'007;

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

std::vector<unsigned> divisors(unsigned x, unsigned ub)
{
    std::vector<unsigned> v;
    for (unsigned i = 1; i <= ub && i * i <= x; ++i) {
        if (x % i == 0) {
            v.push_back(i);

            if (i * i != x && x / i <= ub)
                v.push_back(x / i);
        }
    }

    std::sort(v.begin(), v.end(), std::greater<unsigned>());

    return v;
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> c(1+n);
    c[0] = 1;
    for (const unsigned x : a) {
        for (const unsigned d : divisors(x, n)) {
            if (d <= n)
                c[d] = (c[d] + c[d-1]) % M;
        }
    }

    unsigned k = 0;
    for (size_t i = 1; i <= n; ++i)
        k = (k + c[i]) % M;

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
