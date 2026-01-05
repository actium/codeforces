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

void solve(const std::vector<size_t>& a)
{
    const size_t n = a.size();

    size_t sum = 0, max = 0;
    for (size_t i = 0; i < n; ++i) {
        sum += a[i];
        max = std::max(max, a[i]);
    }

    answer(std::max(2 * sum / n + 1, max));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

