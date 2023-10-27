#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(size_t n, const std::vector<unsigned>& a, const std::vector<unsigned>& t)
{
    const size_t k = a.size();

    std::vector<unsigned> v(n, ~0u / 2);
    for (size_t i = 0; i < k; ++i)
        v[a[i]-1] = t[i];

    for (size_t i = 1; i < n; ++i) {
        v[i] = std::min(v[i], v[i-1] + 1);
        v[n-1-i] = std::min(v[n-1-i], v[n-i] + 1);
    }

    answer(v);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(k), t(k);
    std::cin >> a >> t;

    solve(n, a, t);
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
