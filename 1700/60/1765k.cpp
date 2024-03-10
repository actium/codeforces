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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& a)
{
    const size_t n = a.size();

    integer s = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j)
            s += a[i][j];
    }

    unsigned x = ~0u;
    for (size_t i = 0; i < n; ++i)
        x = std::min(x, a[i][n-1-i]);

    answer(s - x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
    std::cin >> a;

    solve(a);

    return 0;
}
