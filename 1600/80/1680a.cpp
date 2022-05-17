#include <iostream>

using range_t = std::pair<unsigned, unsigned>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const range_t& r1, const range_t& r2)
{
    const unsigned k1 = std::max(r1.first, r2.first);
    const unsigned k2 = std::min(r1.second, r2.second);

    answer(k1 <= k2 ? k1 : r1.first + r2.first);
}

void test_case()
{
    range_t r1, r2;
    std::cin >> r1 >> r2;

    solve(r1, r2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
