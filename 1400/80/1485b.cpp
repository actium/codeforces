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

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r, size_t k)
{
    const size_t n = a.size();

    std::vector<unsigned> d(1+n);
    for (size_t i = 0; i < n; ++i)
        d[i+1] = d[i] + a[i] - (i > 0 ? a[i-1] : 0) - 1;

    for (const auto& q : r)
        answer(d[q.second] - d[q.first] + q.first - 1 + k - q.second);
}

int main()
{
    size_t n, q, k;
    std::cin >> n >> q >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(a, r, k);

    return 0;
}
