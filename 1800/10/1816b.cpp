#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& v)
{
    const char* separator = "";
    for (const T x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void solve(unsigned n)
{
    std::vector<std::vector<unsigned>> a(2, std::vector<unsigned>(n));
    for (size_t i = 0; i < n; i += 2) {
        a[0][i] = 2 * n - i;
        a[0][n-1-i] = n - i;
        a[1][i] = i + 1;
        a[1][n-1-i] = 2 * n - 1 - i;
    }

    std::cout << a[0] << '\n';
    std::cout << a[1] << '\n';
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
