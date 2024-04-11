#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    unsigned p = 0, s = n, q = 0;

    const auto check = [&](size_t i, size_t j, int k) {
        if (k > q) {
            p = i;
            s = n - j;
            q = k;
        }
    };

    a.push_back(0);

    unsigned c = 0, k = 1;
    for (size_t i = 0, j = 0; j <= n; ++j) {
        c += (a[j] < 0);
        k += (std::abs(a[j]) == 2);

        if (a[j] == 0) {
            while (c % 2 == 1) {
                c -= (a[i] < 0);
                k -= (std::abs(a[i]) == 2);
                ++i;
            }
            check(i, j, k);
            i = j + 1;
            k = 1;
        }

        if (c % 2 == 0)
            check(i, j + 1, k);
    }

    answer(p, s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
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
