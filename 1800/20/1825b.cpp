#include <algorithm>
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

void solve(int n, int m, std::vector<int>& b)
{
    std::sort(b.begin(), b.end());

    if (m < n)
        std::swap(n, m);

    const auto evaluate = [&](size_t x, size_t y, size_t z) {
        const auto r1 = std::minmax(b[x], b[y]);
        const auto r2 = std::minmax(b[x], b[z]);
        return (r1.second - r1.first) * (m - 1) * n + (r2.second - r2.first) * (n - 1);
    };

    answer(std::max(evaluate(0, n * m - 1, n * m - 2), evaluate(n * m - 1, 0, 1)));
}

void test_case()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> b(n * m);
    std::cin >> b;

    solve(n, m, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
