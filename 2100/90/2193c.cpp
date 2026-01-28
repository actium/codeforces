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

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& b, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size();

    for (size_t i = 0; i < n; ++i)
        a[i] = std::max(a[i], b[i]);

    for (size_t i = n-1; i > 0; --i)
        a[i-1] = std::max(a[i-1], a[i]);

    std::vector<unsigned> ps(1+n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    for (const auto& q : r)
        answer(ps[q.second] - ps[q.first-1]);
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(a, b, r);
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
