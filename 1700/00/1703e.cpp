#include <iostream>
#include <string>
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

void solve(const std::vector<std::string>& a)
{
    const size_t n = a.size();

    unsigned k = 0;
    for (size_t i = 0; i < n / 2; ++i) {
        for (size_t j = i, x = n - 1; j < x - i; ++j) {
            const unsigned q = a[i][j] - '0' + a[j][x-i] - '0' + a[x-i][x-j] - '0' + a[x-j][i] - '0';
            k += std::min(q, 4 - q);
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n);
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
