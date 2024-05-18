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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t x[20] = {}, k = 1;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < 20; ++j) {
            if ((a[i] & 1 << j) != 0) {
                k = std::max(k, i - x[j] + 1);
                x[j] = i + 1;
            }
        }
    }
    for (size_t j = 0; j < 20; ++j) {
        if (x[j] != 0)
            k = std::max(k, n - x[j] + 1);
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
