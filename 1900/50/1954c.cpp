#include <iostream>
#include <string>

void answer(const std::string& x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(std::string& x, std::string& y)
{
    const size_t n = x.length();

    for (size_t i = 0; i < n; ++i) {
        if (x[i] > y[i])
            std::swap(x[i], y[i]);
    }

    for (size_t i = 0; i < n; ++i) {
        if (x[i] < y[i]) {
            std::swap(x[i], y[i]);
            break;
        }
    }

    answer(x, y);
}

void test_case()
{
    std::string x, y;
    std::cin >> x >> y;

    solve(x, y);
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
