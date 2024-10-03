#include <algorithm>
#include <iostream>
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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& d, const std::vector<unsigned>& a)
{
    const size_t n = d.size(), m = a.size();

    std::vector<unsigned> p(m);
    for (size_t i = 0; i < m; ++i)
        p[i] = i + 1;

    const auto check = [&](unsigned k) {
        std::vector<unsigned> s(1+m);
        for (size_t i = 0; i < k; ++i)
            s[d[i]] = i + 1;

        std::sort(p.begin(), p.end(), [&](unsigned i, unsigned j) {
            return s[i] < s[j];
        });

        unsigned t = 0;
        for (const unsigned i : p) {
            t += a[i-1] + 1;
            if (t > s[i])
                return false;
        }
        return true;
    };

    if (!check(n))
        return no_answer();

    unsigned lb = 0, ub = n;
    while (ub - lb > 1) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> d(n), a(m);
    std::cin >> d >> a;

    solve(d, a);

    return 0;
}
