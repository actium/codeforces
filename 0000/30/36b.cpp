#include <iostream>
#include <string>
#include <vector>

constexpr size_t t[2][5] = {
    { 2, 4, 8, 16, 32 },
    { 3, 9, 27, 81, 243 },
};

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void paint(std::vector<std::string>& c, size_t i, size_t j, size_t m, const std::vector<std::string>& p)
{
    const size_t n = p.size(), q = m / n;

    for (size_t di = 0; di < n; ++di) {
        for (size_t dj = 0; dj < n; ++dj) {
            if (p[di][dj] == '*')
                continue;

            if (m == n) {
                c[i+di][j+dj] = '.';
            } else {
                paint(c, i + di * q, j + dj * q, q, p);
            }
        }
    }
}

void solve(const std::vector<std::string>& p, size_t k)
{
    const size_t n = p.size(), m = t[n-2][k-1];

    std::vector<std::string> c(m, std::string(m, '*'));
    paint(c, 0, 0, m, p);

    answer(c);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> p(n);
    std::cin >> p;

    solve(p, k);

    return 0;
}
