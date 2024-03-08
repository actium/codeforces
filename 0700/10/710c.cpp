#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& v)
{
    const char* separator = "";
    for (const T x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& x : v)
        std::cout << x << '\n';
}

void solve(unsigned n)
{
    const size_t x = n / 2;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
    for (size_t i = 0, v = 1; i < x; ++i) {
        for (size_t j = i; j < x; ++j) {
            a[i][j] = 2 * v++;
            a[i][n-1-j] = 2 * v++;
            a[n-1-i][n-1-j] = 2 * v++;
            a[n-1-i][j] = 2 * v++;
        }
    }
    for (size_t i = 0, v = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (a[i][j] == 0)
                a[i][j] = 1 + 2 * v++;
        }
    }

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
