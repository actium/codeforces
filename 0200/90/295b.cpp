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

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<std::vector<unsigned>>& a, const std::vector<unsigned>& x)
{
    const size_t n = x.size();

    std::vector<integer> s(n);
    for (size_t k = 1; k <= n; ++k) {
        const size_t u = x[n-k] - 1;

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j)
                a[i][j] = std::min(a[i][j], a[i][u] + a[u][j]);
        }

        for (size_t i = n-k; i < n; ++i) {
            for (size_t j = n-k; j < n; ++j)
                s[n-k] += a[x[i]-1][x[j]-1];
        }
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
    std::cin >> a;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(a, x);

    return 0;
}
