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

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size() + 1;

    std::vector<unsigned> d(n);
    for (const unsigned x : p)
        ++d[x-1];

    std::sort(d.begin(), d.end(), std::greater<unsigned>());

    while (d.back() == 0)
        d.pop_back();

    const auto check = [&](unsigned k) {
        const size_t m = d.size();

        unsigned e = 1;
        for (size_t i = 0; i < m; ++i) {
            if (d[i] > k - i)
                e += d[i] - (k - i);
        }
        return k >= m + e;
    };

    unsigned lb = 0, ub = n;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n-1);
    std::cin >> p;

    solve(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
