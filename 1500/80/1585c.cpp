#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer d)
{
    std::cout << d << '\n';
}

void solve(const std::vector<int>& x, size_t k)
{
    std::vector<unsigned> v[2];
    for (const int q : x)
        v[q>0].push_back(std::abs(q));

    for (size_t i = 0; i < 2; ++i) {
        v[i].push_back(0);
        std::sort(v[i].begin(), v[i].end());
    }

    const auto d = [k](const std::vector<unsigned>& x) {
        integer s = 0;
        for (int i = x.size() - 1; i > 0; i -= k)
            s += 2 * x[i];

        return s;
    };

    answer(d(v[0]) + d(v[1]) - std::max(v[0].back(), v[1].back()));
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> x(n);
    std::cin >> x;

    solve(x, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
