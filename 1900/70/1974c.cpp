#include <array>
#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    integer k = 0;
    {
        std::map<std::pair<unsigned, unsigned>, unsigned> f[3];
        std::map<std::array<unsigned, 3>, unsigned> g;
        for (size_t i = 2; i < n; ++i) {
            k += f[0][{ a[i-1], a[i-2] }]++;
            k += f[1][{ a[i-2], a[i-0] }]++;
            k += f[2][{ a[i-0], a[i-1] }]++;
            k -= 3 * g[{ a[i-2], a[i-1], a[i-0] }]++;
        }
    }
    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
