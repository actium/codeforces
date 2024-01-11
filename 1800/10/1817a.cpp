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

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size(), m = 1 << __builtin_clz(1) - __builtin_clz(n) + 1;

    std::vector<unsigned> p(1 + n);
    for (size_t i = 2; i < n; ++i) {
        if (a[i-2] >= a[i-1] && a[i-1] >= a[i])
            p[i] = 1;
    }
    for (size_t i = 1; i <= n; ++i)
        p[i] += p[i-1];

    for (const std::pair<unsigned, unsigned>& q : r) {
        const unsigned d = q.second - q.first + 1;
        answer(d - (d > 1 ? p[q.second-1] - p[q.first] : 0));
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(a, r);

    return 0;
}
