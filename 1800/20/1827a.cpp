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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    unsigned k = 1;
    for (size_t i = 0; i < n; ++i) {
        const unsigned c = n - (std::upper_bound(a.begin(), a.end(), b[n-1-i]) - a.begin());
        k = 1ull * k * (c - i) % 1000000007;
    }

    answer(k);
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
