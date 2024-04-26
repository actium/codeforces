#include <algorithm>
#include <iostream>
#include <vector>

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

void solve(std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::pair<unsigned, unsigned> s = { ~0u, 0 };
    for (size_t i = k; i < n; ++i)
        s = std::min(s, std::make_pair(a[i] - a[i-k], (a[i] + a[i-k]) / 2));

    answer(s.second);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
