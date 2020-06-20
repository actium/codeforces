#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<size_t>& x, const std::vector<size_t>& y)
{
    const size_t n = x.size();

    size_t sums[2] = {};
    for (size_t i = 0; i < n; ++i) {
        sums[0] += x[i];
        sums[1] += y[i];
    }

    answer(sums[1] <= sums[0]);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> x(n);
    std::cin >> x;

    std::vector<size_t> y(n);
    std::cin >> y;

    solve(x, y);

    return 0;
}

