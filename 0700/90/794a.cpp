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

void solve(size_t a, size_t b, size_t c, const std::vector<size_t>& x)
{
    const size_t n = x.size();

    size_t k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (x[i] > b && x[i] < c)
            ++k;
    }

    answer(k);
}

int main()
{
    size_t a, b, c;
    std::cin >> a >> b >> c;

    size_t n;
    std::cin >> n;

    std::vector<size_t> x(n);
    std::cin >> x;

    solve(a, b, c, x);

    return 0;
}

