#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<int>& a, unsigned x)
{
    const size_t n = a.size();

    int sum = 0;
    for (size_t i = 0; i < n; ++i)
        sum += a[i];

    answer((abs(sum) + x - 1) / x);
}

int main()
{
    size_t n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, x);

    return 0;
}

