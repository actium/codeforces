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

    std::vector<unsigned> p(1 + n), s(1 + n);
    for (size_t i = 0; i < n; ++i) {
        p[1 + i] = p[i] + a[i];
        s[n-1-i] = s[n-i] + (1 - a[n-1-i]);
    }

    integer k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 1)
            k += s[i];
    }

    integer q = k;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] == 1)
            q = std::max(q, k - s[i+1] + p[i]);
        else
            q = std::max(q, k - p[i] + s[i+1]);
    }

    answer(q);
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
