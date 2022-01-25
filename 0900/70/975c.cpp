#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void solve(const std::vector<integer>& a, const std::vector<integer>& k)
{
    const size_t n = a.size(), q = k.size();

    std::vector<integer> ps(1+n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    integer d = 0;
    for (size_t i = 0; i < q; ++i) {
        d += k[i];

        const auto it = std::upper_bound(ps.cbegin(), ps.cend(), d);
        if (it == ps.end()) {
            answer(n);
            d = 0;
        } else {
            answer(std::distance(it, ps.cend()));
        }
    }
}

int main()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<integer> a(n), k(q);
    std::cin >> a >> k;

    solve(a, k);

    return 0;
}
