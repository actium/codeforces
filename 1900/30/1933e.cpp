#include <iostream>
#include <vector>

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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size(), m = r.size();

    std::vector<unsigned> ps(1 + n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    const auto evaluate = [&](size_t l, size_t r, unsigned u) {
        const long long k = ps[r+1] - ps[l];
        return k * (2 * u - k + 1) / 2;
    };

    const auto query = [&](size_t l, unsigned u) {
        size_t lb = l, ub = n;
        while (lb + 1 < ub) {
            const size_t mid = (lb + ub) / 2;
            (evaluate(l, mid, u) <= evaluate(l, mid > lb ? mid - 1 : lb, u) ? ub : lb) = mid;
        }
        return 1 + lb;
    };

    std::vector<unsigned> v(m);
    for (size_t i = 0; i < m; ++i)
        v[i] = query(r[i].first - 1, r[i].second);

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t q;
    std::cin >> q;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(a, r);
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
