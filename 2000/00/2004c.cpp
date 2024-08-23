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

void solve(std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    unsigned v = 0;
    for (size_t i = 1; i < n; i += 2)
        v += a[i-1] - a[i];

    v -= std::min(v, k);

    if (n % 2 == 1)
        v += a[n-1];

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

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
