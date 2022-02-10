#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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

void solve(const std::vector<std::string>& a)
{
    constexpr unsigned oo = ~0u;

    const size_t k = a[0].length();

    std::vector<size_t> p(k);
    for (size_t i = 0; i < k; ++i)
        p[i] = i;

    const auto f = [&](const std::string& x) {
        unsigned v = 0;
        for (const size_t i : p)
            v = v * 10 + (x[i] - '0');

        return v;
    };

    unsigned d = oo;
    do {
        unsigned l = oo, u = 0;
        for (const std::string& x : a) {
            const unsigned v = f(x);
            l = std::min(l, v);
            u = std::max(u, v);
        }
        d = std::min(d, u - l);
    } while (std::next_permutation(p.begin(), p.end()));

    answer(d);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
