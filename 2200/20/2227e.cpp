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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    integer k = 0;

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        while (!p.empty() && a[i] <= a[p.back()])
            p.pop_back();

        k = std::max<integer>(k, p.empty() ? i : i - p.back() - 1);
        p.push_back(i);
    }

    unsigned b = ~0u;
    for (size_t i = n-1; ~i != 0; --i) {
        b = std::min(b, a[i]);
        k += a[i] - b;
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
