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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& d, integer x)
{
    const size_t n = d.size();

    std::vector<integer> pd(1 + 2 * n), ph(1 + 2 * n);
    for (size_t i = 0; i < 2 * n; ++i) {
        pd[i+1] = pd[i] + d[i % n];
        ph[i+1] = ph[i] + d[i % n] * (d[i % n] + 1ull) / 2;
    }

    integer h = 0;
    for (auto it = std::lower_bound(pd.begin(), pd.end(), x); it != pd.end(); ++it) {
        auto jt = std::lower_bound(pd.begin(), it, *it - x);
        if (*it - *jt < x)
            --jt;

        const integer ed = (*it - *jt) - x;
        h = std::max(h, ph[it - pd.begin()] - ph[jt - pd.begin()] - ed * (ed + 1) / 2);
    }

    answer(h);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    integer x;
    std::cin >> x;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(d, x);

    return 0;
}
