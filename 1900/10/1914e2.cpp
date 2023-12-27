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

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) {
        return a[i] + b[i] < a[j] + b[j];
    });

    for (size_t i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            --a[p.back()];
            b[p.back()] = 0;
        } else {
            a[p.back()] = 0;
            --b[p.back()];
        }
        p.pop_back();
    }

    integer d = 0;
    for (size_t i = 0; i < n; ++i) {
        d += a[i];
        d -= b[i];
    }

    answer(d);
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
