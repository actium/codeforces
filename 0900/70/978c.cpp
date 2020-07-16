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

void solve(const std::vector<integer>& a, const std::vector<integer>& b)
{
    const size_t n = a.size();
    const size_t m = b.size();

    integer x = 0;
    for (size_t i = 0, j = 0; i < n && j < m; ++i) {
        while (j < m && b[j] <= x + a[i]) {
            std::cout << 1 + i << ' ' << b[j] - x << '\n';
            ++j;
        }
        x += a[i];
    }
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<integer> a(n);
    std::cin >> a;

    std::vector<integer> b(m);
    std::cin >> b;

    solve(a, b);

    return 0;
}

