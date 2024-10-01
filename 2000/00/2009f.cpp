#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<integer, integer>>& r)
{
    const size_t n = a.size();

    std::vector<integer> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + a[i];

    const auto sum = [&](integer k) {
        const size_t m = k / n, r = m + k % n;

        return p[n] * m + (r > n ? p[n] + p[r%n] : p[r]) - p[m];
    };

    for (const std::pair<integer, integer>& q : r)
        answer(sum(q.second) - sum(q.first - 1));
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<integer, integer>> r(q);
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
