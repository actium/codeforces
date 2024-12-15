#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::vector<int>>& a)
{
    const size_t n = a[0].size();

    int s = 0, x = std::min(a[0][0], a[1][0]);
    for (size_t i = 0; i < n; ++i) {
        s += std::max(a[0][i], a[1][i]);
        x = std::max(x, std::min(a[0][i], a[1][i]));
    }

    answer(s + x);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<int>> a(2, std::vector<int>(n));
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
