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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& r, const std::vector<unsigned>& x)
{
    const auto check = [&](size_t k) {
        std::vector<unsigned> p(1 + n);
        for (size_t i = 0; i < k; ++i)
            p[x[i]] = 1;

        for (size_t i = 1; i <= n; ++i)
            p[i] += p[i-1];

        for (const std::pair<unsigned, unsigned>& q : r) {
            const unsigned v = p[q.second] - p[q.first-1];
            if (2 * v > q.second - q.first + 1)
                return true;
        }
        return false;
    };

    size_t lb = 0, ub = x.size();
    if (!check(ub))
        return no_answer();

    while (lb + 1 < ub) {
        const size_t mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> r(m);
    std::cin >> r;

    size_t q;
    std::cin >> q;

    std::vector<unsigned> x(q);
    std::cin >> x;

    solve(n, r, x);
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
