#include <iostream>

using segment_t = std::pair<unsigned, unsigned>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const segment_t& a, const segment_t& b)
{
    const unsigned s = std::max(a.first, b.first), t = std::min(a.second, b.second);

    answer(s > t ? 1 : (a.first != b.first) + t - s + (a.second != b.second));
}

void test_case()
{
    segment_t a, b;
    std::cin >> a >> b;

    solve(a, b);
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
