#include <algorithm>
#include <iostream>
#include <vector>

using integer = long long;

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

void solve(const std::vector<int>& a, std::vector<size_t>& b)
{
    const size_t n = a.size(), m = b.size();

    std::vector<integer> ps(1+n);
    for (size_t i = 0; i < n; ++i)
        ps[i+1] = ps[i] + a[i];

    b.push_back(0);

    std::sort(b.begin(), b.end());

    integer v = ps[n];
    for (size_t i = 1; i <= m; ++i) {
        const auto d = ps[b[i]] - ps[b[i-1]];
        v += std::abs(d) - d;
    }
    
    answer(v);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::cin >> a;

    std::vector<size_t> b(m);
    std::cin >> b;

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
