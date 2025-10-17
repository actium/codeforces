#include <iostream>

using point_t = std::pair<unsigned, unsigned>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, const point_t& k, const point_t& d)
{
    unsigned v = 0;

    if (d.first > k.first)
        v = std::max(v, d.first);

    if (d.first < k.first)
        v = std::max(v, n - d.first);

    if (d.second > k.second)
        v = std::max(v, d.second);

    if (d.second < k.second)
        v = std::max(v, n - d.second);

    answer(v);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    point_t k, d;
    std::cin >> k >> d;

    solve(n, k, d);
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
