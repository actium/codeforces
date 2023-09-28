#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using integer = unsigned long long;

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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const integer n = a.size();

    const auto ai = std::min_element(a.begin(), a.end());
    const auto bi = std::min_element(b.begin(), b.end());

    const integer s1 = *ai * n + std::accumulate(b.begin(), b.end(), 0ull);
    const integer s2 = *bi * n + std::accumulate(a.begin(), a.end(), 0ull);

    answer(std::min(s1, s2));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
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
