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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b)
{
    const size_t n = a.size(), m = b.size();

    std::sort(a.begin(), a.end(), std::greater<unsigned>());
    std::sort(b.begin(), b.end());

    integer s = 0;
    for (size_t i = 0, j = 0; i < n; ++i, ++j) {
        if (j >= m || i + b[j] > n) {
            s += a[i];
        } else {
            for (unsigned k = 1; k < b[j]; ++k)
                s += a[i++];
        }
    }

    answer(s);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n), b(k);
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
