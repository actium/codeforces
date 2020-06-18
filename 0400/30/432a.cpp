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

void solve(const std::vector<size_t>& y, size_t k)
{
    const size_t n = y.size();

    size_t count = 0;
    for (size_t i = 0; i < n; ++i)  {
        if (y[i] + k <= 5)
            ++count;
    }

    answer(count / 3);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<size_t> y(n);
    std::cin >> y;

    solve(y, k);

    return 0;
}

