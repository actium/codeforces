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
    const size_t n = a.size(), m = n - n / 4;

    std::sort(a.begin(), a.end(), std::greater<unsigned>());
    std::sort(b.begin(), b.end(), std::greater<unsigned>());

    unsigned v1 = 0, v2 = 0;
    for (size_t i = 0; i < m; ++i) {
        v1 += a[i];
        v2 += b[i];
    }

    unsigned k = 0;
    for (size_t j = m; v1 < v2; ++j) {
        v1 += 100;
        v2 += (j < n ? b[j] : 0);
        ++k;

        if ((n + k) % 4 == 0) {
            v1 -= a[n - (n + k) / 4];
            v2 -= (j < n ? b[j--] : 0);
        }
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
