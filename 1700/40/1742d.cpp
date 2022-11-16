#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<int> p(1 + 1000);
    for (size_t i = 0; i < n; ++i)
        p[a[i]] = 1 + i;

    int x = -1;
    for (unsigned i = 1; i <= 1000; ++i) {
        if (p[i] == 0)
            continue;

        for (unsigned j = 1; j <= 1000; ++j) {
            if (p[j] == 0 || std::gcd(i, j) != 1)
                continue;

            x = std::max(x, p[i] + p[j]);
        }
    }

    answer(x);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
