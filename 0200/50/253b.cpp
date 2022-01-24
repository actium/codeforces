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

void answer(size_t x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& c)
{
    const size_t n = c.size();

    std::sort(c.begin(), c.end());

    size_t x = n;
    for (size_t i = 0; i < n; ++i) {
        const size_t k = std::distance(std::upper_bound(c.cbegin(), c.cend(), 2 * c[i]), c.cend());
        x = std::min(x, i + k);
    }

    answer(x);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c);

    return 0;
}
