#include <iostream>
#include <vector>

constexpr std::pair<int, int> d[] = {
    { 0, 1 },
    { 1, 0 },
    { 0, -1 },
    { -1, 0 },
};

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

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& x : v)
        std::cout << x << '\n';
}

void solve(size_t n)
{
    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n, n * n));
    {
        size_t r = (n-1) / 2, c = (n-1) / 2;
        for (size_t i = 3, x = 0; x < n * n; ++x) {
            a[r][c] = x;

            const std::pair<int, int> u = d[(i+1)%4];
            if (r + u.first < n && c + u.second < n && a[r+u.first][c+u.second] > x)
                i = (i + 1) % 4;

            r += d[i].first;
            c += d[i].second;
        }
    }

    answer(a);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    solve(n);
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
